# -*- coding: utf-8 -*-

##
## Re:VIEWを拡張し、インライン命令とブロック命令を追加する
##

module ReVIEW

  ## インライン命令「@<clearpage>{}」を宣言
  Compiler.definline :clearpage         ## 改ページ
  Compiler.definline :seqsplit          ## 行の折り返し

  ## ブロック命令「//textleft{ ... //}」等を宣言
  ## （ここでは第2引数が「0」なので、引数なしのブロック命令になる。
  ##   もし第2引数が「1..3」なら、//listのように必須引数が1つで
  ##   非必須引数が2という意味になる。）
  Compiler.defblock :textleft, 0        ## 左寄せ
  Compiler.defblock :textright, 0       ## 右寄せ
  Compiler.defblock :textcenter, 0      ## 中央揃え

  Compiler.defblock :panelsection, 0..1  ## panel-collapse
  Compiler.defblock :codepanelsection, 0..1  ## panel-collapse（コマンドのみ）


  module LATEXBuilderOverride

    def column_begin(level, label, caption)
      blank
      @doc_status[:column] = true

      target = nil
      if label
        target = "\\hypertarget{#{column_label(label)}}{}"
      else
        target = "\\hypertarget{#{column_label(caption)}}{}"
      end

      @doc_status[:caption] = true
      puts '\\begin{reviewcolumn}[' + caption + ']'
      puts target
      @doc_status[:caption] = nil

      if level <= @book.config['toclevel'].to_i
        puts "\\addcontentsline{toc}{#{HEADLINE[level]}}{#{compile_inline(caption)}}"
      end
    end

    def column_end(_level)
      puts '\\end{reviewcolumn}'
      blank
      @doc_status[:column] = nil
    end

    def quote(lines)
      puts '\begin{quote}'
      lines.each do |line|
        puts '\noindent'
        puts detab(line)
      end
      puts '\end{quote}'
    end

    def inline_tt(str)
      macro('reviewtt', escape(str))
    end

  end

  ## LaTeX用の定義
  class LATEXBuilder

    prepend LATEXBuilderOverride

    ## 改ページ
    def inline_clearpage(str)
      '\clearpage'
    end

    ## 行の折り返し
    def inline_seqsplit(str)
      escaped_str = escape_latex(str)
      "\\seqsplit{#{escaped_str}}"
    end

    ## 左寄せ
    def textleft(lines)
      puts '\begin{flushleft}'
      puts lines
      puts '\end{flushleft}'
    end

    ## 右寄せ
    def textright(lines)
      puts '\begin{flushright}'
      puts lines
      puts '\end{flushright}'
    end

    ## 中央揃え
    def textcenter(lines)
      puts '\begin{center}'
      puts lines
      puts '\end{center}'
    end

    ## panel-collapse
    def panelsection(lines, heading)
      blank
      puts '\vspace*{\baselineskip}'
      puts '\begin{tcolorbox}[sharp corners,
                              colframe=gray,
                              colback=white,
                              colbacktitle=gray,
                              coltitle=white, fonttitle=\ttfamily\bfseries, title=' + heading + ']'
      lines.each do |line|
        puts detab(line)
      end
      puts '\end{tcolorbox}'
      blank
    end

    ## panel-collapse（コマンドのみ）
    def codepanelsection(lines, heading)
      blank
      puts '\vspace*{\baselineskip}'
      puts '\begin{tcolorbox}[sharp corners,
                              colframe=gray,
                              colback=black,
                              coltext=white,
                              fontupper=\ttfamily\small,
                              colbacktitle=gray,
                              coltitle=white, fonttitle=\ttfamily\bfseries, title=' + heading + ']'
      lines.each do |line|
        puts detab(line)
      end
      puts '\end{tcolorbox}'
      blank
    end

  end


  ## HTML（ePub）用の定義
  class HTMLBuilder

    ## 改ページはHTMLにはない
    def inline_clearpage(str)
      puts '<p></p>'
      puts '<p></p>'
    end

    ## 左寄せ
    def textleft(lines)
      puts '<div style="text-align:left">'
      puts lines
      puts '</div>'
    end

    ## 右寄せ
    def textright(lines)
      puts '<div style="text-align:right">'
      puts lines
      puts '</div>'
    end

    ## 中央揃え
    def textcenter(lines)
      puts '<div style="text-align:center">'
      puts lines
      puts '</div>'
    end

  end

end
