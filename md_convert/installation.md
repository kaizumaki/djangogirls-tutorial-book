# 家でチュートリアルに挑戦する方へ

[Django Girls のイベント](https://djangogirls.org/events/)ではなく、あなたが一人家でこのチュートリアルに挑戦しているのであれば、このチャプターは無視して次のチャプター [インターネットのしくみ](../how_the_internet_works/README.md) に進みましょう。

このチャプターは、インストールに関連する部分を集約してまとめたページです。これらのインストール手順は、以降のチャプターに含まれていますので、そちらを参照してください。 Django Girlsのイベントでは「インストールDay」としてワークショップ前日に、環境設定やインストールをまとめて行っています。ワークショップの都合上、イベント中に環境設定で躓いてしまわないためです。

まとめてインストールする方が都合が良い方は、このチャプターを参照してください。 しかし、いろんなものをパソコンにインストールする前に、一体それらが何なのか学びたい方は、このチャプターを飛ばしてください。これ以降のページでインストールの手順やその説明を行っています。

頑張りましょう！

# インストール

ワークショップに参加してWebサイト（ブログ）を作成する方は、このページの手順に従って、あらかじめ必用なインストールを行っておきましょう。ワークショップ当日はコードを書くことに集中できますよ。

<!--sec data-title="Chromebook setup (if you're using one)"
data-id="chromebook_setup" data-collapse=true ces--> 

Chromebookをお持ちでない場合は、[このセクションをスキップ](http://tutorial.djangogirls.org/en/installation/#install-python) できます。 もし利用している場合は、普通のインストールの作業とは少し異なります。 インストール手順の残りの部分は無視できます。

### Cloud 9

Cloud 9 はコードエディタや、インストール、書き込み、およびソフトウェアを実行できるインターネット上で動いているコンピューターへのアクセスを与えるツールです。 チュートリアルをやっている間、Cloud 9はあなたの*ローカルマシーン*のように動きます。 クラスメートがOS XやUbuntu、Windowsでやっているのと同じようにターミナル上でコマンドを実行していても、あなたのターミナルはCloud 9がセットアップしたどこかのコンピューターにつながっています。

1. [Chrome ウェブストア](https://chrome.google.com/webstore/detail/cloud9/nbdmccoknlfggadpfkmcpnamfnbkmkcp)から Cloud 9 を インストールする
2. [C9.io](https://c9.io) に行く
3. アカウントにサインアップします
4. *新しいワークスペースを作成*をクリック
5. 名前は*django-girls*とします
6. *Blank*を選択(下の行の右側から 2 番目のオレンジ色のロゴ)

インターフェイスには、サイドバー、テキストが書かれた大きなメインウィンドウ、下部に小さなウィンドウがあり、次の表示が見えると思います。

{% filename %}Cloud 9{% endfilename %}

    yourusername:~/workspace $
    

この下部のエリアはあなたの*ターミナル*で、Cloud 9 があなたの指示を待っています。ウィンドウサイズを少し大きくすることもできます。

### 仮想環境

仮想環境 (virtualenvとも呼ばれます) は、取り組んでいるプロジェクト用に、便利なコンピューターコードを詰め込んでおけるプライベートボックスのようなものです。 様々なプロジェクトの様々なコードがプロジェクト間で混ざってしまわないようにこれを使います。

Cloud 9のインターフェイスのうち、下部のターミナルで次を実行します。

{% filename %}Cloud 9{% endfilename %}

    sudo apt update
    sudo apt install python3.6-venv
    

それでも問題が解決しない場合は、コーチに相談してください。

次に、以下を実行します：

{% filename %}Cloud 9{% endfilename %}

    mkdir djangogirls
    cd djangogirls
    python3.6 -mvenv myvenv
    source myvenv/bin/activate
    pip install django~={{ book.django_version }}
    

(最後の行はチルダに続けてイコール記号をつけることに気をつけてください: ~=)

### GitHub

[GitHub](https://github.com)のアカウントを作成しましょう。

### PythonAnywhere

Django Girlsチュートリアルには、デプロイメントと呼ばれるものに関するセクションが含まれています。これはあなたの新しいWebアプリケーションの原動力となるコードを取得して、それを公にアクセス可能なコンピューター（サーバーと呼ばれます）に移動するプロセスです。これにより、あなたのやったことを他の人が見ることができるようになります。

Chromebookでチュートリアルを行うとき、すでにインターネットに接続されているコンピュータ（ラップトップとは対照的に）を使用しているので、この作業は少し変に思えます。 しかし、Cloud 9のワークスペースを「開発中」の場所、PythonAnywhere をより完成したものを披露する場所として考えると役に立ちます。

したがって、新しいPythonAnywhereアカウントにサインアップしてください。 [ www.pythonanywhere.com ](https://www.pythonanywhere.com)

<!--endsec-->



# Pythonのインストール

> 家で１人でこのチャプターに挑戦している方へ：この章は、動画（英語）もあるので参考にしてください。 [Installing Python & Code Editor](https://www.youtube.com/watch?v=pVTaqzKZCdA)
> 
> このセクションはGeek Girls Carrots (https://github.com/ggcarrots/django-carrots) のチュートリアルをベースに作成しました。

Django は、Pythonで開発されています。なにをするにせよ、まずはPythonが必要です。インストールしましょう！ Python 3.6 をインストールします。3.5以前のバージョンをインストール済みの場合は、アップグレードしてください。

<!--sec data-title="Install Python: Windows" data-id="python_windows" data-collapse=true ces-->

Windowsをお使いのかたは、まずシステム情報を開き、システムの種類が32-bitバージョンか64-bitバージョンかを確認します（システム情報の開き方：Windowsキー + Pause/Break キー　もしくは　コントロールパネル＞システムとセキュリティ＞システムを開く）。 Python for Windowsは、https://www.python.org/downloads/windows/ からダウンロードできます。 「Latest Python 3 Release - Python x.x.x」のリンクをクリックしてください。 お使いのコンピュータが**64ビット**版のWindowsを実行している場合は、**Windows x86-64 executable installer**をダウンロードしてください。 32ビット版の場合は、**Windows x86 executable installer**をダウンロードします。 インストーラをダウンロードしたら、それを実行して（ダブルクリックして）インストーラの指示に従ってください。

**インストール時に必ず「Add Python 3.6 to PATH」にチェックをいれましょう**：

![Pythonのパスを通すのを忘れないようにしてください。](../python_installation/images/python-installation-options.png)

次のステップでは、Windowsコマンドラインを使用します（コマンドラインについては後ほど詳しく教えます）。 現時点では、コマンドを入力する必用がある場合、スタートメニューから検索フィールドに「コマンドプロンプト」入力してください。 （Windwosのバージョンが古い場合、「スタートメニュー」をクリックして、表示されるアプリ一覧から「Windowsシステムツール」を選んで、「コマンドプロンプト」をクリックしてください。）あるいは、「Windowsキー」を押しながら「R」キーを押すと、「ファイル名を指定して実行」が現れます。 コマンドプロンプトを開くには、そこに "cmd" と入力してenterキーを押します。

!["ファイル名を指定して実行"で、"cmd"と入力してください](../python_installation/images/windows-plus-r.png)

注意：古いバージョンのWindows（7、Vista、またはそれ以前のバージョン）を使用していて、Python 3.6.xインストーラがエラーで失敗した場合、次のいずれかを試みることができます：

1. すべてのWindowsアップデートをインストールして、Python 3.6を再インストールしてみる。
2. [古いバージョンのPython](https://www.python.org/downloads/windows/)をインストールしてみる。例えば[3.4.6](https://www.python.org/downloads/release/python-346/)。

古いバージョンのPythonをインストールする場合、インストール画面は上記のものとは多少異なる場合があります。 下にスクロールして「Add python.exe to Path」のところを左クリックして「Will be installed on local hard drive（ローカルハードドライブにインストールされます）」を選択してください：

![古いバージョンのパスを追加してください](../python_installation/images/add_python_to_windows_path.png)

<!--endsec-->

<!--sec data-title="Install Python: OS X" data-id="python_OSX"
data-collapse=true ces-->

> **注意**：OS XにPythonをインストールする前に、Macの設定でApp Store以外のパッケージをインストールできるようにする必要があります。 「システム環境設定」（「アプリケーション」フォルダ内）に移動し、「セキュリティとプライバシー」、「一般」タブの順にクリックします。 「ダウンロードしたアプリを許可する」が「Mac App Store」に設定されている場合は、「Mac App Storeと識別された開発者」に変更します。

Webサイトからダウンロードしてインストールしましょう。 https://www.python.org/downloads/

* *macOS 64-bit/32-bit installer* ファイルをダウンロードしてください。
* *python-3.6.5-macosx10.6.pkg*をダブルクリックしてインストーラーを実行してください。

<!--endsec-->

<!--sec data-title="Install Python: Linux" data-id="python_linux"
data-collapse=true ces-->

おそらくほとんどの場合、すぐに使えるPythonがすでにインストールされているでしょう。インストールされているか（とそれがどのバージョンか）を確認するため、コンソールを起動して次のコマンドを打ってください。

{% filename %}command-line{% endfilename %}

    $ python3 --version
    Python 3.6.5
    

このとき、バージョンの数字の最後が違っていたとしても（例えば、3.6.0など）、アップグレードする必要はありません。 もし、Pythonがインストールされていない場合、あるいはバージョンが古い場合は、次の指示に従ってインストールしてください。

<!--endsec-->

<!--sec data-title="Install Python: Debian or Ubuntu" data-id="python_debian" data-collapse=true ces-->

次のコマンドをコンソールに打って下さい。

{% filename %}command-line{% endfilename %}

    $ sudo apt install python3.6
    

<!--endsec-->

<!--sec data-title="Install Python: Fedora" data-id="python_fedora"
data-collapse=true ces-->

次のコマンドをコンソールに打って下さい。

{% filename %}command-line{% endfilename %}

    $ sudo dnf install python3
    

古いバージョンのFedoraの場合は、コマンド `dnf` が見つからないというエラーが表示されます。その場合は、代わりに yum を使用してください。

<!--endsec-->

<!--sec data-title="Install Python: openSUSE" data-id="python_openSUSE"
data-collapse=true ces-->

次のコマンドをコンソールに打って下さい。

{% filename %}command-line{% endfilename %}

    $ sudo zypper install python3
    

<!--endsec-->

インストールされているか確認するために、コマンドプロンプトを開いて次のように`Python3`コマンドを入力してください。

{% filename %}command-line{% endfilename %}

    $ python3 --version
    Python 3.6.1
    

**注意：** Windowsをお使いで`python3`が見つからないエラーが出る場合、 代わりに`python`と入力して、バージョンがPython3.6と出てくるか確認してください。（`3`を抜いてみましょう）

* * *

分からない時や、質問がある時は、コーチに質問してくださいね。 ときどき上手くいかないこともあります。そんな時は、経験豊富な人に聞くといいですよ。



# コードエディタのインストール

本当にたくさんのエディタがありますが、どれを使うかは、結局は、ほとんど個人の好みの問題です。 ほとんどのPythonプログラマは、PyCharmなど、複雑ですが非常に強力なIDE（統合開発環境）というものを使っています。 しかし、初心者にとってはIDEはそれほど適していないかもしれないので、同じくらい強力で、もっとシンプルなものをオススメします。

オススメのエディタは下記に挙げますが、気軽にコーチに質問して好みや特徴ををきいてみてください。

## Gedit

Geditはオープン ソースの無料エディタで、すべてのOSで利用可能です。

[ダウンロード](https://wiki.gnome.org/Apps/Gedit#Download)

## Sublime Text 3

Sublime Textは非常に人気のあるエディタで、無料の試用期間があります。簡単にインストールして使用することができ、すべてのOSに対応しています。

[ダウンロード](https://www.sublimetext.com/3)

## Atom

Atom は、GitHubによる新しいエディタです。無料で、オープンソースで、インストールも使い方も簡単です。Windows、OSX、 Linuxで利用可能です.

[ダウンロード](https://atom.io/)

## なんでコードエディタをインストールするの？

なんでWordやNotepadのようなものを使わず、特別なコードエディタをインストールするのかなと思うかもしれません。

まず、コードは**プレーンテキスト**という、何の装飾もない生の文字列でないといけませんが、問題は、WordやTexteditのようなプログラムが生成するのは、実は、プレーンテキストではないということなんです。WordやTexteditは、[RTF（リッチテキストフォーマット）](https://en.wikipedia.org/wiki/Rich_Text_Format)などのような、改造された形式を使って、フォントや書式を持ったリッチテキストを生成します。

2つ目の理由は、コードエディタは、コードを編集することに特化しているので、コードを意味によって色づけして強調したり、引用符を自動的に閉じたりするような、便利な機能を提供できます。

あとで、こういった動作が全てわかるようになります。すぐに、信頼できる使い古したコードエディタを、お気に入りのツールの一つだと思うようになると思いますよ^^



# virtualenvのセットアップとDjangoのインストール

> このチャプターの一部はGeek Girls Carrots (https://github.com/ggcarrots/django-carrots) のチュートリアルに基づいています。
> 
> このチャプターの一部はCreative Commons Attribution-ShareAlike 4.0 International License のライセンスによる[django-marcador tutorial](http://django-marcador.keimlink.de/)に基づいています. このdjango-marcador tutorialはMarkus Zapke-Gründemann らが著作権を保有しています。 

## 仮想環境

Django をインストールする前に、あなたのコーディング環境を、きれいにしておく便利な道具をインストールしてもらいます。 このステップをとばすこともできますが、しかし、このステップをとばすことは全くお勧めしません。 可能な限りベストなセットアップで始めることは将来のたくさんのトラブルからあなたを救うはずですから！

さあ、**仮想環境（virtual environment )**(*virtualenv*とも呼ばれています）を作成してみましょう。 仮想環境（virtual environment）ではプロジェクト単位であなたのPython/Djangoのセットアップを他から隔離します。 これは、あなたがひとつのウェブサイトにおこなったどんな変更も、あなたが開発している他のサイトに影響を及ぼさないということです。 便利でしょ？

あなたがしなければならないのは、あなたが`仮想環境（virtual environment）`を作成したいディレクトリを見つけることです（たとえばホームディレクトリなどです）。 Windowsでは、ホームディレクトリは、`C:\Users\Name`と書かれているかもしれません (`Name`はあなたのログインネームです)。

> **補足：**　Windowsの方は、ディレクトリ名に特殊文字やアクセント記号を含まないよう気をつけてください。もし、ユーザー名が特殊文字を含む場合は、`C:\djangogirls` のようなディレクトリを作成してください。

このチュートリアルのために、ホームディレクトリに新しいディレクトリ`djangogirls`を作成します。

{% filename %}command-line{% endfilename %}

    $ mkdir djangogirls
    $ cd djangogirls
    

`myvenv`という仮想環境（virtual environment）を作成します。一般的なコマンドは以下のようになります：

{% filename %}command-line{% endfilename %}

    $ python3 -m venv myvenv
    

<!--sec data-title="Virtual environment: Windows" data-id="virtualenv_installation_windows"
data-collapse=true ces-->

新しい`virtualenv`を作成するために、コマンドプロンプトを開き（コマンドプロンプトについては何章か前にお話ししましたね。覚えてますか？）、`python -m venv myvenv`を実行して下さい。たとえばこのように入力します：

{% filename %}command-line{% endfilename %}

    C:\Users\Name\djangogirls> python -m venv myvenv
    

`myvenv` というところが、あなたの`virtualenv（仮想環境）` の名前です。 どんな名前でも使うことができますが、必ず小文字で表記し、スペース・アクセント記号・特殊文字は入れないでください。 短い名前にしておくのもいいアイデアですーあなたはこの名前を何度も参照しますから！

<!--endsec-->

<!--sec data-title="Virtual environment: Linux and OS X" data-id="virtualenv_installation_linuxosx"
data-collapse=true ces-->

LinuxやOS Xで`virtualenv`を作るときは、`python3 -m venv myvenv`と実行するだけです。 たとえばこんな感じです：

{% filename %}command-line{% endfilename %}

    $ python3 -m venv myvenv
    

`myvenv` は、あなたの `仮想環境(virtualenvironment)` の名前です。 どんな名前でも使うことができますが、必ず小文字で表記し、スペースは入れないでください。 短い名前にしておくのもいいアイデアですーあなたはこの名前を何度も参照しますから！

> **補足：**DebianやUbuntuのバージョンによっては、以下のエラーが出ることがあります。
> 
> {% filename %}command-line{% endfilename %}
> 
>     The virtual environment was not created successfully because ensurepip is not available.  On Debian/Ubuntu systems, you need to install the python3-venv package using the following command.
>        apt install python3-venv
>     You may need to use sudo with that command.  After installing the python3-venv package, recreate your virtual environment.
>     
> 
> この場合、エラー内の指示にしたがって、`python3-venv`のパッケージをインストールしましょう。 {% filename %}command-line{% endfilename %}
> 
>     $ sudo apt install python3-venv
>     
> 
> **補足：**DebianやUbuntuのバージョンによっては、この仮想環境を実行すると、次のようなエラーがでます。
> 
> {% filename %}command-line{% endfilename %}
> 
>     Error: Command '['/home/eddie/Slask/tmp/venv/bin/python3', '-Im', 'ensurepip', '--upgrade', '--default-pip']' returned non-zero exit status 1
>     
>     
> 
> このエラーを回避するために、代わりに`virtualenv`コマンドを使います。
> 
> {% filename %}command-line{% endfilename %}
> 
>     $ sudo apt install python-virtualenv
>     $ virtualenv --python=python3.6 myvenv
>     
> 
> **補足：**もし以下のようなエラーがでたら、
> 
> {% filename %}command-line{% endfilename %}
> 
>     E: Unable to locate package python3-venv
>     
> 
> 代わりに次のコマンドを実行してください。
> 
> {% filename %}command-line{% endfilename %}
> 
>     sudo apt install python3.6-venv
>     

<!--endsec-->

## 仮想環境の操作

上に示したコマンドは仮想環境（基本的には一連のディレクトリとファイル）を含む`myvenv` という名前（あるいはあなたが選んだ名前）のディレクトリを生成します。次に我々がしたいのは、これを実行し、開始することです。

<!--sec data-title="Working with virtualenv: Windows" data-id="virtualenv_windows"
data-collapse=true ces-->

実行して、仮想環境を起動します。

{% filename %}command-line{% endfilename %}

    C:\Users\Name\djangogirls > myvenv\Scripts\activate
    

> **補足：**Windows 10では、`execution of scripts is disabled on this system`というエラーがWindows PowerShellに出ることがあります。 その場合は、Windows PowerShellを「管理者として開く」で、管理者権限で新しくウィンドウを開いてください。 そして、仮想環境を開始する前に、以下のコマンドを入力してください。
> 
> {% filename %}command-line{% endfilename %}
> 
>     C:\WINDOWS\system32> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned
>         Execution Policy Change
>         The execution policy helps protect you from scripts that you do not trust. Changing the execution policy might expose you to the security risks described in the about_Execution_Policies help topic at http://go.microsoft.com/fwlink/?LinkID=135170. Do you want to change the execution policy? [Y] Yes  [A] Yes to All  [N] No  [L] No to All  [S] Suspend  [?] Help (default is "N"): A
>     

<!--endsec-->

<!--sec data-title="Working with virtualenv: Linux and OS X" data-id="virtualenv_linuxosx"
data-collapse=true ces-->

実行して、仮想環境を起動します。

{% filename %}command-line{% endfilename %}

    $ source myvenv/bin/activate
    

`myvenv`のところをあながた選んだ`仮想環境(virtualenvironment)`名に置き換えることを忘れないで下さいね！

> **備考:** `source` ではできない場合もあります。その場合は、代わりに以下のように入力してみてください：
> 
> {% filename %}command-line{% endfilename %}
> 
>     $ . myvenv/bin/activate
>     

<!--endsec-->

`virtualenv` が起動すると、プロンプトの行頭に`(myvenv)`が現れます。

Virtual environment(仮想環境) の中で作業しているとき、`python`は自動的に正しいバージョンの`Python`を参照しますので、`python3`の代わりに`python`を使うことができます.

OK,これでDjangoのインストール前に入れておきたい依存関係の準備がすべて整いました。いよいよDjangoのインストールです！

## Djangoのインストール

今度はあなたの`virtualenv`を起動したので、Djangoをインストールすることができます。

これを行う前に、Djangoのインストールに使用する最新バージョンの`pip`がインストールされている必要があります。

{% filename %}command-line{% endfilename %}

    (myvenv) ~$ python3 -m pip install --upgrade pip
    

### Requirementsファイルによってパッケージをインストールする

Requirementsファイルは`pip install`でインストールするためのパッケージリストが記載されているファイルです:

前にインストールしたコードエディタを使用して、最初に `requirements.txt` ファイルを `djangogirls/` フォルダーの中に作ります:

    djangogirls
    └───requirements.txt
    

`djangogirls/requirements.txt` ファイル中に以下のテキストを追加します:

{% filename %}djangogirls/requirements.txt{% endfilename %}

    Django~={{ book.django_version }}
    

そして、`pip install -r requirements.txt` を実行してDjangoをインストールします。

{% filename %}command-line{% endfilename %}

    (myvenv) ~$ pip install -r requirements.txt
    Collecting Django~={{ book.django_version }} (from -r requirements.txt (line 1))
      Downloading Django-{{ book.django_version }}-py3-none-any.whl (7.1MB)
    Installing collected packages: Django
    Successfully installed Django-{{ book.django_version }}
    

<!--sec data-title="Installing Django: Windows" data-id="django_err_windows"
data-collapse=true ces-->

> Windowsでpipを呼んだときにエラーが起きた場合は、あなたのプロジェクトのパス名がスペース・アクセント・特殊文字を含んでいないか確認してみて下さい （例 `C:\Users\User Name\djangogirls`）。 もし含まれている場合は、ディレクトリを他のスペース・アクセント・特殊文字が含まれていない場所（`C:\djangogirls`など）で作成することを検討してみてください。 新しいディレクトリに新しい仮想環境を作成してから、古いディレクトリを削除して、上記のコマンドを試してください。 （仮想環境のディレクトリは、絶対パスが使われているので、移動させてもうごきません。）

<!--endsec-->

<!--sec data-title="Installing Django: Windows 8 and Windows 10" data-id="django_err_windows8and10"
data-collapse=true ces-->

> Djangoをインストールしようとしてコマンドラインがフリーズして動かなくなってしまうことがあります。その時は、以下のコマンドを代わりに入力してみてください。
> 
> {% filename %}command-line{% endfilename %}
> 
>     C:\Users\Name\djangogirls> python -m pip install -r requirements.txt
>     

<!--endsec-->

<!--sec data-title="Installing Django: Linux" data-id="django_err_linux"
data-collapse=true ces-->

> Ubuntu 12.04でpipを呼んだときにエラーが起きた場合は、仮想環境(virtualenv) 内にpipを再インストールするために`python -m pip install -U --force-reinstall pip` を実行して下さい。

<!--endsec-->

以上です！あなたは（ついに）Djangoアプリケーションを作成する準備が整いました！



# Gitのインストール

Gitはたくさんのプログラマが利用する「バージョン管理システム」です。 このソフトウェアは、特定のバージョンを後で呼び出すことができるように、時間の経過とともにファイルへの変更を追跡することができます。 Microsoft Wordの”トラックの変更（track changes)"のようですが、はるかに強力です。

## Gitのインストール

<!--sec data-title="Installing Git: Windows" data-id="git_install_windows"
data-collapse=true ces-->

[git-scm.com](https://git-scm.com/) からGitをダウンロードすることができます。 1つのステップを除いて「次へ」を押して進んで大丈夫です。「PATH環境を調整する(Adjusting your PATH environment)」というステップでは、「WindowsコマンドプロンプトからGitとオプションのUnixツールを使用する(Use Git and optional Unix tools from the Windows Command Prompt)」（一番下の選択肢）を選択します。 それ以外はデフォルトの設定値で構いません。 改行コードの変換(Configuring the line ending conversions)については、「Checkout Windows-style, commit Unix-style line endings」の選択で大丈夫です。

インストールが正常に終了した後、コマンドプロンプトまたはPowerShellを再起動することを忘れないでください。<!--endsec-->

<!--sec data-title="Installing Git: OS X" data-id="git_install_OSX"
data-collapse=true ces-->

[git-scm.com](https://git-scm.com/) からGitをダウンロードし、指示に従ってください。

> **注** OS X 10.6,10.7、または10.8を実行している場合は、ここからgitのバージョンをインストールする必要があります: [Git installer for OS X Snow Leopard](https://sourceforge.net/projects/git-osx-installer/files/git-2.3.5-intel-universal-snow-leopard.dmg/download)

<!--endsec-->

<!--sec data-title="Installing Git: Debian or Ubuntu" data-id="git_install_debian_ubuntu"
data-collapse=true ces-->

{% filename %}command-line{% endfilename %}

```bash
$ sudo apt install git
```

<!--endsec-->

<!--sec data-title="Installing Git: Fedora" data-id="git_install_fedora"
data-collapse=true ces-->

{% filename %}command-line{% endfilename %}

```bash
$ sudo dnf install git
```

<!--endsec-->

<!--sec data-title="Installing Git: openSUSE" data-id="git_install_openSUSE"
data-collapse=true ces-->

{% filename %}command-line{% endfilename %}

```bash
$ sudo zypper install git
```

<!--endsec-->



# GitHubのアカウント作成

[GitHub.com](https://www.github.com)にアクセスし、Sign upを押して無料の新規アカウントを作成してください。

# PythonAnywhereのアカウント作成

PythonAnywhere はクラウド上のサーバーでPythonのコードを走らせるためのサービスです。私たちはこれを私たちのサイトをホスティングして、インターネット上で動かし続けるために使います。

PythonAnywhere で「Beginner」アカウントにサインアップしましょう（クレジットカードのいらない無料利用枠で大丈夫です）。

* [https://www.pythonanywhere.com](https://www.pythonanywhere.com/)

![PythonAnywhere サインアップページが表示する無料の「Beginner」アカウント作成ボタン](../deploy/images/pythonanywhere_beginner_account_button.png)

> **注** ユーザー名を選ぶとき、あなたのブログのURLが`あなたのユーザー名.pythonanywhere.com`になることを覚えておいて下さい。ですから、自分のニックネームかあなたのブログが何についてのブログか分かるような名前を選んでみて下さい。

## PythonAnywhere APIトークンの作成

これはあなたが一度だけ行う必要があるものです。 PythonAnywhere にサインアップしたとき、ダッシュボードページが表示されます。 右上にある「Account」ページへのリンクをクリックし、それから「API Token」タブを選択し、「Create new API token」ボタンをクリックします。

![アカウントページのAPIトークンタブ](../deploy/images/pythonanywhere_create_api_token.png)



# 読んでみよう

お疲れ様でした！これで準備が整いました。ワークショップが始まるまで時間あれば、いくつかのチャプターを読んでおくとよいでしょう。

* [インターネットのしくみ](../how_the_internet_works/README.md)

* [コマンドラインを使ってみよう](../intro_to_command_line/README.md)

* [Pythonをはじめよう](../python_introduction/README.md)

* [Djangoってなに？](../django/README.md)

# ワークショップを楽しんでください！

インストールDayにここまでのインストールが無事に出来た方は、ワークショップでは、[プロジェクトを作成しよう！](../django_start_project/README.md)のチャプターからはじめてください。