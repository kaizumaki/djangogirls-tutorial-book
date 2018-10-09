
= Python入門

//quote{
このチャプターの一部はGeek Girls Carrotsのチュートリアルをもとにしています。(https://github.com/ggcarrots/django-carrots)

//}


さあ、コードを書いてみましょう！


== Pythonプロンプト

//quote{
家で１人でこのパートに挑戦している方へ：このパートと続くパートは、動画（英語）もあるので参考にしてください。 @<href>{https://www.youtube.com/watch?v=MO63L4s-20U,Python Basics: Integers\, Strings\, Lists\, Variables and Errors}

//}


Pythonであそぶために、@<b>{コマンドライン} を開きましょう。 やり方は、チャプター @<chapref>{intro_to_command_line} で学びましたね。



準備ができたら、次の指示に従ってやってみましょう。



Pythonコンソールを開きましょう。Windowsなら @<tt>{python} 、Mac OSやLinuxなら @<tt>{python3} とタイプして @<tt>{Enter} キーを押してください。



//cmd[command-line]{
$ python3
Python 3.6.1 (...)
Type "help", "copyright", "credits" or "license" for more information.
>>>
//}

== 最初のPythonコマンド！


Pythonのコマンドが走ると、プロンプト記号が @<tt>{>>>} に変わりました。 これは、今Pythonの言語を実行できますという意味です。 @<tt>{>>>} はタイプしなくていいですよ – Pythonがあなたの代わりにやってくれます。



Pythonコンソールを終わる時は、@<tt>{exit()} とタイプするか、ショートカット @<tt>{Ctrl + Z}（Windows）、@<tt>{Ctrl + D}（Mac/Linux）で終了です。 そうするともう @<tt>{>>>} は出なくなります。



けど、今はまだコンソールを終了しないで、もっと動かして学びましょう。簡単な計算からはじめましょう。@<tt>{2 + 3} とタイプして、@<tt>{Enter} キーを押してください。



//cmd[command-line]{
>>> 2 + 3
5
//}


できました！答えがでてきましたね。Pythonは計算ができます。他にも、次のようなコマンドを試してみましょう。

 * @<tt>{4 * 5}
 * @<tt>{5 - 1}
 * @<tt>{40 / 2}



2の3乗のような指数の計算は、次のようにタイプします。


//cmd[command-line]{
>>> 2 ** 3
8
//}


ちょっとの間楽しんであそんでみたら、またココに戻ってきてくださいね。:)



お分かりのとおり、Pythonはステキな計算機ですね。他になにができるんだろう…と思ったら、次にいってみましょう。


== 文字列


あなたのお名前を次のようにクォーテーションをつけてタイプしてください。



//cmd[command-line]{
>>> "Ola"
'Ola'
//}


はじめてのString（文字列）が完成です！ Stringとは、文字の集合のことです。 シングルクォーテーション (@<tt>{'}) あるいは、ダブルクォーテーション (@<tt>{"}) で囲います。 最初と最後は同じ記号にしてください。 クォーテーションの中が文字列であることを意味しています。



複数の文字列を結合することもできます。次のように試してみましょう。



//cmd[command-line]{
>>> "Hi there " + "Ola"
'Hi there Ola'
//}


文字列を繰り返すためには、演算子を使って繰り返し回数を指定することもできます。



//cmd[command-line]{
>>> "Ola" * 3
'OlaOlaOla'
//}


アポストロフィーを文字列の中に含めたい場合は、２通りの方法があります。



まずは、ダブルクォーテーションを使う方法です。



//cmd[command-line]{
>>> "Runnin' down the hill"
"Runnin' down the hill"
//}


あるいは、バックスラッシュ (``) を使う方法もあります。


//cmd[command-line]{
>>> 'Runnin\' down the hill'
"Runnin' down the hill"
//}


できましたか？次に、あなたの名前を大文字に変えてみましょう。次のように記述してください。



//cmd[command-line]{
>>> "Ola".upper()
'OLA'
//}


ここで @<tt>{upper} @<strong>{関数 (function)} を使うことができましたね！ 関数 ( @<tt>{upper()} など) は、呼び出したオブジェクト ( @<tt>{"Ola"} のことです) に対してどのような手順でどのような処理をするかをひとまとめにしたものです。



あなたの名前の文字数を知りたいときは、その @<strong>{関数 (function)} もあります！



//cmd[command-line]{
>>> len("Ola")
3
//}


どうして、文字列の後に @<tt>{.} をつけて関数を呼び出したり ( @<tt>{"Ola".upper()} のように)、あるいは、先に関数を呼び出してかっこの中に文字列をいれているのか、と疑問に思ったかもしれません。 そうですね。時に、オブジェクトに結びついた関数というのがあります。例えば、@<tt>{upper()} は、文字列にのみ実行される関数です。 私たちはこれを @<strong>{メソッド (method)} と呼びます。 それとは別に、特定のオブジェクトに関連せず、異なるタイプのオブジェクトに対して実行できる関数があります。例えば @<tt>{len()} ですね。 @<tt>{len} 関数の引数として @<tt>{"Ola"} をかっこの中にいれているのです。


=== まとめ


文字列はだいじょうぶですね。ここまでに学んだことをまとめましょう。

 * @<strong>{プロンプト} – Pythonプロンプトにコマンド（コード）を入力すると、答えがかえってきます。
 * @<strong>{数値と文字列} – 数値は計算に、文字列はテキストに使われます。
 * @<strong>{演算子} – 例えば @<tt>{+} や @<tt>{*} のように、値を計算して新しい値を返します。
 * @<strong>{関数} – @<tt>{upper()} や @<tt>{len()} のようにオブジェクトに対して行う機能のことです。



すべてのプログラミング言語に共通する基礎になります。 もう少し難易度の高いものに挑戦してみましょう。準備はいいですか？


== エラー


さて、新しいことをやってみましょう。あなたの名前の文字数を数えたように、数字の文字数は数えられるでしょうか？ @<tt>{len(304023)} と記述して、@<tt>{Enter} キーを押してみましょう。


//cmd[command-line]{
>>> len(304023)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: object of type 'int' has no len()
//}


はじめてのエラーがでました！（今回はチュートリアルで用意されていましたが）思ったように動かないことは学ぶ上で大事です！



オブジェクトタイプ"int" (integers, 数値) は文字数がありませんと言っています。では、どうすればよいでしょうか？この数字を文字列として扱えれば、文字数を数えられるはずですよね？


//cmd[command-line]{
>>> len(str(304023))
6
//}


うまく行きました！ @<tt>{str} 関数を @<tt>{len} のかっこの中に記述しました。@<tt>{str()} はその中身を文字列に変換します。

 * @<tt>{str} 関数は、@<strong>{文字列} に変換します。
 * @<tt>{int} 関数は、文字列や数値を @<strong>{整数} に変換します。


//quote{
重要！: 数字は文字列にすることはできますが、全ての文字が数字に変換できるわけではありません。 例えば @<tt>{int('hello')} は数字にはなりませんよね？

//}

== 変数


変数（variables）は、プログラミングの重要なコンセプトです。 後で使うためにつける単なる名札ではありません。 プログラマーは変数を使ってデータを保管したり、 コードを読みやすくして、後でそれが何だったか覚えておかなくてもいいようにします。



変数 @<tt>{name} を新しくつくってみましょう。


//cmd[command-line]{
>>> name = "Ola"
//}


name イコール（=）"Ola" とタイプします。



見てのとおり、プログラムは、なにも返してくれませんね。では、変数がきちんとあるか、どうやって確かめたらいいのでしょうか？ @<tt>{name} とタイプして、@<tt>{Enter} キーを押してください。


//cmd[command-line]{
>>> name
'Ola'
//}


やりました！あなたのはじめての変数ができましたね！代入する値を変えることもできます。


//cmd[command-line]{
>>> name = "Sonja"
>>> name
'Sonja'
//}


変数には関数も使えます。


//cmd[command-line]{
>>> len(name)
5
//}


素晴らしいですね！変数は、数値にも使えますよ。


//cmd[command-line]{
>>> a = 4
>>> b = 6
>>> a * b
24
//}


もしも、間違えた変数名を使ってしまったら、どうなるでしょうか？予想できますか？やってみましょう！


//cmd[command-line]{
>>> city = "Tokyo"
>>> ctiy
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'ctiy' is not defined
//}


エラーになりました！ 前回とは違うエラータイプです。@<strong>{NameError} という、初めてみるエラータイプですね。 作成されていない変数を使った時は、Pythonがエラーを教えてくれます。 もし、このエラーに出くわしたら、記述したコードにタイプミスがないか確認してください。



ちょっと遊んで、何ができるか試してみてくださいね！


== print 関数


次に挑戦してみましょう。


//cmd[command-line]{
>>> name = 'Maria'
>>> name
'Maria'
>>> print(name)
Maria
//}


単に @<tt>{name} とタイプした時は、Pythonインタプリタが、変数'name'の文字列@<b>{表現（representation）}を返します。ここでは、シングルクォーテーション（''）に囲まれた M-a-r-i-aという文字の集まりです。 しかし、@<tt>{print(name)}と記述した時は、Pythonは変数の中身を出力します。クォーテーションはありません。



これからさらに詳しくみていきますが、@<tt>{print()} は、関数から出力をする時や、複数行の出力を行うときにも便利です。


== リスト


数値と文字列の他にも、すべてのオブジェクトタイプを勉強しておきましょう。 今から@<strong>{list} というものを紹介していきます。 リストは、その名のとおり、オブジェクトの並びをもつものですね。 :)



まずはリストを作りましょう。


//cmd[command-line]{
>>> []
[]
//}


はい、このリストは空っぽです。使いにくいですよね。では、くじ引きの番号のリストを作りましょう。 この番号を何度も繰り返し書きたくはないから、同時に変数に代入してしまいましょう。



//cmd[command-line]{
>>> lottery = [3, 42, 12, 19, 30, 59]
//}


よし、これでリストができました！このリストで何をしましょうか？では、くじ引きの番号がいくつあるか、数えてみましょう。何の関数を使えばいいか、予想できますか？すでに知っていますよね！


//cmd[command-line]{
>>> len(lottery)
6
//}


そうです！@<tt>{len()} がリストにあるオブジェクトの数を取得できます。便利ですね。では、くじ引きの番号をソートしてみましょう。


//cmd[command-line]{
>>> lottery.sort()
//}


これは何も返してきません。これはリストに表示される番号を、順番に並べ替えただけです。再度出力して、確かめてみましょう。


//cmd[command-line]{
>>> print(lottery)
[3, 12, 19, 30, 42, 59]
//}


ご覧のとおり、小さい順に並び替えられましたね。おめでとう！



逆順に並び替えてみたくなりましたか？やってみましょう。


//cmd[command-line]{
>>> lottery.reverse()
>>> print(lottery)
[59, 42, 30, 19, 12, 3]
//}


リストに何かを追加したいときは、次のようにコマンドを記述してください。


//cmd[command-line]{
>>> lottery.append(199)
>>> print(lottery)
[59, 42, 30, 19, 12, 3, 199]
//}


最初の数字だけを出力したいときは、@<strong>{インデックス(index)} を使って指定することができます。 インデックスは、アイテムがリストのどこにあるかを指す番号です。 リストの先頭の要素から順に「０」、次に「１」と割り当てられています。 次のとおり試してみてください。


//cmd[command-line]{
>>> print(lottery[0])
59
>>> print(lottery[1])
42
//}


このように、リスト名と要素のインデックスを [] に記述することで、指定した要素を取り出すことができます。



リストから要素を消すには、これまで学んできたインデックスと @<tt>{pop()} メソッドを使います。 例で試してみましょう。リストの最初の要素を削除しています。


//cmd[command-line]{
>>> print(lottery)
[59, 42, 30, 19, 12, 3, 199]
>>> print(lottery[0])
59
>>> lottery.pop(0)
59
>>> print(lottery)
[42, 30, 19, 12, 3, 199]
//}


お見事！



他のインデックスも試して遊んでみてください。例えば、 6, 7, 1000, -1, -6, -1000 などをインデックスに指定するとどうなるでしょうか。コマンドを実行する前に予測してみましょう。結果はどうですか？



ご参考に、こちらのドキュメントにリストメソッドがすべて記されています。 https://docs.python.org/3/tutorial/datastructures.html


== 辞書（ディクショナリ）

//quote{
家で１人でこのパートに挑戦している方へ：このパートは、動画（英語）もあるので参考にしてください。 @<href>{https://www.youtube.com/watch?v=ZX1CVvZLE6c,Python Basics: Dictionaries}

//}


辞書(ディクショナリ)について確認しましょう。リストに似ていますが、インデックスのかわりにキーと呼ばれる識別子で値を参照します。キーは文字列も数値も使えます。ディクショナリは次のように @<tt>{{\}} 括弧で囲んで作成します。


//cmd[command-line]{
>>> {}
{}
//}


これで中身が空っぽのディクショナリができましたね。やったね！



では、つぎのコマンドを記述してみましょう。 (あなた自身の情報に値をおきかえてみてもいいですよ）


//cmd[command-line]{
>>> participant = {'name': 'Ola', 'country': 'Poland', 'favorite_numbers': [7, 42, 92]}
//}


このコマンドで、@<tt>{participant} という名前の変数をつくって、３つのキーと値をもつ要素を作成しました。

 * キー @<tt>{name} が指す値は @<tt>{'Ola'} (@<tt>{string} オブジェクト)
 * キー @<tt>{country} が指す値は @<tt>{'Poland'} (@<tt>{string} オブジェクト)
 * キー @<tt>{favorite_numbers} が指す値はリスト @<tt>{[7, 42, 92]} (数字を3つ持つ@<tt>{list})



次のように書くと各キーの値を確認できます。


//cmd[command-line]{
>>> print(participant['name'])
Ola
//}


リストに似ていますね。しかし、ディクショナリでは、インデックスを覚えておく必要がなく、キーの名前でいいのです。



もし存在しないキーを参照しようとすると、どうなるでしょうか？予想できますか？実際にやってみましょう！


//cmd[command-line]{
>>> participant['age']
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 'age'
//}


またエラーです。今回は @<strong>{KeyError} というエラーが出ました。Pythonは、このディクショナリにキー @<tt>{'age'} は存在しませんよ、と教えてくれています。



ディクショナリとリストはどう使い分ければよいのでしょうか？そうですね、これはゆっくり考えてみるべきポイントですね！この後の行を読むまえに、答えを考えてみてください。

 * 必要なのは、順序付けられた一連のアイテムですか？　リストを使いましょう。
 * キーに対応する値が必要？キーから値を参照する？　ディクショナリを使いましょう。



ディクショナリやリストは、作ったあとに変更できるオブジェクトです。これを @<b>{mutable} と呼びます。次のように、ディクショナリを作ったあとで、新しいキーと値を追加することができます。


//cmd[command-line]{
>>> participant['favorite_language'] = 'Python'
//}


リストと同様に、@<tt>{len()} 関数をディクショナリに使ってみましょう。ディクショナリでは、キーと値のペアの数を返します。コマンドを入力してやってみましょう。


//cmd[command-line]{
>>> len(participant)
4
//}


お分かり頂けたでしょうか。 :) では、ディクショナリを使ってもう少し練習してみましょう。準備ができたら、次の行にいってみましょう。



ディクショナリの要素を削除する時は、@<tt>{pop()} メソッドを使います。 例えば、 キー @<tt>{'favorite_numbers'} の要素を削除するには、次のように記述してください。


//cmd[command-line]{
>>> participant.pop('favorite_numbers')
[7, 42, 92]
>>> participant
{'country': 'Poland', 'favorite_language': 'Python', 'name': 'Ola'}
//}


このように、@<tt>{'favorite_numbers'} のキーと値が削除されます。



同様に、次のように記述することで、すでにあるキーの値を変更することができます。


//cmd[command-line]{
>>> participant['country'] = 'Germany'
>>> participant
{'country': 'Germany', 'favorite_language': 'Python', 'name': 'Ola'}
//}


これで、キー @<tt>{'country'} の値は、@<tt>{'Poland'} から @<tt>{'Germany'} に変わりました。面白くなってきましたか？その調子です！


=== まとめ


素晴らしいです！これで、あなたはプログラミングについて沢山のことを学びました。ここまでのところをまとめましょう。

 * @<strong>{エラー} – あなたのコマンドをPythonが理解できない時にエラーが表示されます。
 * @<strong>{変数} – コードを簡単にまた読みやすくするために、文字や数値などのオブジェクトにつける名札。
 * @<strong>{リスト} – 複数の値（要素）が順に並んでいるもの。
 * @<strong>{ディクショナリ} – キーと値のペアの集合です。



次に進む準備はいいですか？ :)


== 比較

//quote{
家で１人でこのパートに挑戦している方へ：このパートは、動画（英語）もあるので参考にしてください。@<href>{https://www.youtube.com/watch?v=7bzxqIKYgf4,Python Basics: Comparisons}

//}


比較することは、プログラミングの醍醐味の１つです。簡単に比較できるものといえば、何でしょうか？そうです、数字ですね。さっそくやってみましょう。


//cmd[command-line]{
>>> 5 > 2
True
>>> 3 < 1
False
>>> 5 > 2 * 2
True
>>> 1 == 1
True
>>> 5 != 2
True
//}


Pythonにいくつか比較する数字をあたえてみました。数字を比較するだけでなく、演算式の答えも比較することができます。便利でしょ？



２つの数字がイコールであるかどうかを比べる時に、イコールの記号が２つ @<tt>{==} 並んでいます。 Pythonを記述する時、イコール１つ @<tt>{=}は、変数に値を代入するときに使います。 ですので、値同士が等しいかどうか比較するときは、必ず @<strong>{必ず} イコール記号２つ @<tt>{==} を記述してください。 等しくないことを比較するときは、 上記の例のように @<tt>{!=} と記述します。



次の２つはどうでしょうか。


//cmd[command-line]{
>>> 6 >= 12 / 2
True
>>> 3 <= 2
False
//}


@<tt>{>} と @<tt>{<} は簡単でしたね。@<tt>{>=} と @<tt>{<=} はどうでしょうか？それぞれの意味は、次のとおりです。

 * x @<tt>{>} y : x は y より大きい
 * x @<tt>{<} y : x は y より小さい
 * x @<tt>{<=} y : x は y 以下
 * x @<tt>{>=} y : x は y 以上



すばらしい! もう少しやってみましょう。


//cmd[command-line]{
>>> 6 > 2 and 2 < 3
True
>>> 3 > 2 and 2 < 1
False
>>> 3 > 2 or 2 < 1
True
//}


複数の数値を比較して複雑になっても、その答えを出してくれます。とても賢いですね。

 * @<strong>{and} – @<tt>{and} の左辺と右辺が共にTrueの場合のみ、True。
 * @<strong>{or} – @<tt>{or} の左辺あるいは右辺の少なくとも１つがTrueの時、True。



"comparing apples to oranges"という英語の表現を聞いたことはありますか？文字通り訳すと「リンゴとオレンジを比較する」となり、「比較にならないものを比較する」という意味です。Pythonでも同じようなことをやってみましょう。


//cmd[command-line]{
>>> 1 > 'django'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: '>' not supported between instances of 'int' and 'str'
//}


Pythonは、数値(@<tt>{int})と文字列(@<tt>{str})の比較はできません。 @<strong>{TypeError} とエラーが表示され、２つのオブジェクトタイプが比較できないことを教えてくれています。


== ブール型（Boolean）


偶然にも、@<strong>{ブール型 (Boolean)} というあたらしいオブジェクトタイプを学びました。



ブール型は、たった２つの値を持ちます。

 * True
 * False



Pythonを記述するときは、Trueの最初は大文字のT、残りは小文字です。 @<strong>{true, TRUE, tRUE は間違いです。– True と記述してください} （False についても同様です。）



ブール型は、次のように変数に代入することもできます。


//cmd[command-line]{
>>> a = True
>>> a
True
//}


このようなこともできます。


//cmd[command-line]{
>>> a = 2 > 5
>>> a
False
//}


ブール型を使って、練習して遊んでみましょう。次のコマンドを試してみてください。

 * @<tt>{True and True}
 * @<tt>{False and True}
 * @<tt>{True or 1 == 1}
 * @<tt>{1 != 2}



おめでとうございます！ブール型を理解することは、プログラミングでとても大事です。ここまでできましたね！


== 保存しよう！

//quote{
家で１人でこのパートに挑戦している方へ：このパートと続くパートは、動画（英語）もあるので参考にしてください。@<href>{https://www.youtube.com/watch?v=dOAg6QVAxyk,Python Basics: Saving files and "If" statement}

//}


ここまでインタプリタでPythonのコードをかいてきました。つまり、コードを１行ずつしか書くことができませんでした。 普通のプログラムはファイルに保存され、@<strong>{インタプリタ} あるいは @<strong>{コンパイラ} でプログラミング言語を処理して実行します。 ここまで、私たちはプログラムを１行ごとにPython @<strong>{インタプリタ} で実行してきました。 ここからは、１行以上のコードを実行していきましょう。次のような流れになります。

 * Pythonインタプリタを終了します。
 * お好きなエディタを起動します。
 * Pythonファイルとしてコードを保存します。
 * 実行します！



これまで使っていたPythonインタプリタを終了しましょう。@<tt>{exit()} 関数を記述してください。


//cmd[command-line]{
>>> exit()
$
//}


これで、コマンドプロンプトに戻りました。



前のチャプター @<href>{../code_editor/README.md,コードエディタ} で、エディタを紹介しました。エディタを起動して、新しいファイルにコードを書いてみましょう。


//emlist[editor][python]{
print('Hello, Django girls!')
//}


あなたは、すでにベテランのPython開発者です。今日学んだコードを自由に書いてみてください。



コードを書いたら、わかりやすい名前をつけて保存しましょう。 @<strong>{python_intro.py} と名前をつけて、デスクトップに保存してください。 ファイル名は何でもかまいません。ここで重要なことは、拡張子を @<strong>{.py} とすることです。 コンピュータにこのファイルは @<strong>{Pythonで実行するファイルです} とおしえます。


//quote{
@<strong>{メモ} コードエディタでは色に注目しましょう！これはとてもクールです。 Pythonコンソールでは、すべての文字は同じ色です。エディタでは、@<tt>{print} 関数は文字列とは違う色がつきます。 これは「シンタックスハイライト」と呼ばれています。エディタは構文（シンタックス）を強調（ハイライト）します。コードを書くとき、これはとても役に立ちます。 色のおかげで、文字列の最後のクォーテーションの書き忘れや、キーワードの名前（この後学ぶ関数の @<tt>{def} など）のタイポに気づくことができます。 これが私たちがコードエディタを使う理由の１つです. :)

//}


ファイルを保存したら、実行してみましょう！コマンドラインのセクションで学んだことを思い出して、ターミナルの @<strong>{ディレクトリを変更} して、デスクトップにしましょう。


//panelsection[Change directory: OS X]{


Macでは、コマンドは次のようになります。


//}


//cmd[command-line]{
$ cd ~/Desktop
//}


//panelsection[Change directory: Linux]{


Linuxでは、次のようになります。("Desktop"のところは"デスクトップ"と表示されているかも知れません)


//}


//cmd[command-line]{
$ cd ~/Desktop
//}


//panelsection[Change directory: Windows Command Prompt]{


Windowsのコマンドプロンプトでは、次のようになります。


//}


//cmd[command-line]{
> cd %HomePath%\Desktop
//}


//panelsection[Change directory: Windows Powershell]{


WindowsのPowerShellでは、次のようになります。


//}


//cmd[command-line]{
> cd $Home\Desktop
//}


うまくできない時は、質問してください。まさにそのためにコーチがここにいます！



次に、ファイルのコードを実行します。


//cmd[command-line]{
$ python3 python_intro.py
Hello, Django girls!
//}


メモ：Windowsでファイルのコードを実行するときは、'python3' の代わりに 'python' とタイプしましょう。


//cmd[command-line]{
> python python_intro.py
//}


できました！これで、あなたはファイルに保存されたPythonプログラムを実行できましたね。いい気分ですね。



では、ここからプログラミングに不可欠のツールを学んでいきましょう。


== If … elif … else


ある条件が成立するときに処理を行いたいという時に用いるのが、@<strong>{if 条件式} です。



では、@<strong>{python_intro.py} ファイルのコードを次のように書き換えてください。


//emlist[python_intro.py][python]{
if 3 > 2:
//}


これを保存して実行すると、次のようなエラーがでます。


//cmd[command-line]{
$ python3 python_intro.py
File "python_intro.py", line 2
         ^
SyntaxError: unexpected EOF while parsing
//}


条件式 @<tt>{3 > 2} が @<tt>{True} の時、どのように処理をすべきかが記述されていませんね。 では、Python に “It works!” と出力してもらいましょう。 @<strong>{python_intro.py} ファイルの中身を、次のとおりに書き換えてください。


//emlist[python_intro.py][python]{
if 3 > 2:
    print('It works!')
//}


２行目をスペース４つでインデントしていることに気が付きましたか？ 条件式が True の時、どのコードを実行するかPythonに知らせる必要があります。 スペース１つでもできますが、ほぼ全員のPythonプログラマーはスペース４つとしています。 タブ１つも、スペース４つと同じです。 タブかスペースか決めたら、変えないようにしましょう。 例えばスペース４つでインデントにしたら、この後もスペース４つでインデントするようにしましょう。インデントにスペースとタブを混ぜてしまうと問題が発生してしまうことがあります。



保存して、もう一度実行してみましょう。



//cmd[command-line]{
$ python3 python_intro.py
It works!
//}


メモ：Windowsでは 'python3' とタイプしてもうまくいかないことを思い出してください。この後ファイルを実行するときは 'python3' の代わりに 'python' とタイプしてくださいね。


=== 条件がTrueじゃないときは？


前述の例では、if文の条件式が True の時だけ、コードが実行されました。Pythonは、@<tt>{elif} や @<tt>{else} といった記述もできます。


//emlist[python_intro.py][python]{
if 5 > 2:
    print('5 is indeed greater than 2')
else:
    print('5 is not greater than 2')
//}


これを実行した場合、次のように出力されます。


//cmd[command-line]{
$ python3 python_intro.py
5 is indeed greater than 2
//}


もし２が５より大きかったら、４行目のコマンドが実行されます。では、@<tt>{elif} はどうなるのでしょうか？


//emlist[python_intro.py][python]{
name = 'Sonja'
if name == 'Ola':
    print('Hey Ola!')
elif name == 'Sonja':
    print('Hey Sonja!')
else:
    print('Hey anonymous!')
//}


実行すると...


//cmd[command-line]{
$ python3 python_intro.py
Hey Sonja!
//}


どうなったかわかりましたか？ @<tt>{elif} を追加する事で、上記の条件（@<tt>{name == 'Ola'}）が True でない場合に実行する条件を追加することができます。



最初の @<tt>{if} の条件分岐の後に、好きなだけ @<tt>{elif} を追加する事ができます。例えば...


//emlist[python_intro.py][python]{
volume = 57
if volume < 20:
    print("It's kinda quiet.")
elif 20 <= volume < 40:
    print("It's nice for background music")
elif 40 <= volume < 60:
    print("Perfect, I can hear all the details")
elif 60 <= volume < 80:
    print("Nice for parties")
elif 80 <= volume < 100:
    print("A bit loud!")
else:
    print("My ears are hurting! :(")
//}


Pythonは上から順番に各条件をテスト、実行し、出力します。


//cmd[command-line]{
$ python3 python_intro.py
Perfect, I can hear all the details
//}

== コメント


コメントは @<tt>{#} で始まる行です。@<tt>{#} の後にはなんでも書くことができ、Pythonはそれを無視します。コメントを書いたコードは、ほかの人にとってもわかりやすくなります。



コメントを書いてみましょう。


//emlist[python_intro.py][python]{
# ボリュームが大きすぎたり小さすぎたりしたら変更する
if volume < 20 or volume > 80:
    volume = 50
    print("That's better!")
//}


コードのすべての行にコメントを書く必要はありません。コメントには、コードの中である処理をする理由や、複雑なコードの動きのまとめを書くと役に立ちます。


=== まとめ


直近のエクササイズを通して、学んだことは、、、

 * @<strong>{比較} – 比較に用いる @<tt>{>}, @<tt>{>=}, @<tt>{==}, @<tt>{<=}, @<tt>{<} そして@<tt>{and}, @<tt>{or} といった演算子があります。
 * @<strong>{ブール型} – @<tt>{True} と @<tt>{False} ２つの値のみを持ちます。
 * @<strong>{ファイルの保存} – コードはファイルに保存することで、大きなプログラムも実行できます。
 * @<strong>{if … elif … else} – 条件分岐することで、特定の条件によって処理を分けて実行することができます。
 * @<strong>{コメント} – あなたがコードについて記述できる行。Pythonは実行しません。



では、このチャプターの最後のパートに挑戦していきましょう！


== 自作の関数！

//quote{
家で１人でこのパートに挑戦している方へ：このパートは、動画（英語）もあるので参考にしてください。@<href>{https://www.youtube.com/watch?v=5owr-6suOl0,Python Basics: Functions}

//}


Pythonには @<tt>{len()} のように関数があったのを覚えていますか？ ここでは、自分で関数を作る方法を学びます。



実行する処理をひとまとめにしたものを関数といいます。 Pythonでは、関数は @<tt>{def} というキーワードからはじまり、引数（ひきすう）を含むことができます。 簡単なものからはじめてみましょう。 @<strong>{python_intro.py} の中身を下記のコードに置き換えてください。


//emlist[python_intro.py][python]{
def hi():
    print('Hi there!')
    print('How are you?')

hi()
//}


あなたの最初の関数を実行する準備ができましたね！



ここであなたは、最後の行になぜ関数の名前を書いたのだろう、と疑問に感じたかもしれません。 これは、Pythonがファイルを読み、上から下へ実行していくからです。 関数を定義したあとに、もう一度その関数を書いて呼び出します。



では実行して、どうなるか見てみましょう。


//cmd[command-line]{
$ python3 python_intro.py
Hi there!
How are you?
//}


メモ：思ったように動かなくても慌てないで！画面の出力は動かない理由をつかむのに役立ちます。

 * @<tt>{NameError} が出ている場合、おそらく何かミスタイプがあります。同じ名前を使っているかチェックしましょう。関数を定義するときは @<tt>{def hi():} としていますか？関数を実行するときは @<tt>{hi()} としていますか？
 * @<tt>{IndentationError} が出ている場合、@<tt>{print} 関数の2行が同じ数のスペースでインデントされているかチェックしましょう。関数の中のコードは同じ数のスベースでインデントされているとPythonは考えます。
 * 画面に何も表示されていない場合、最後の @<tt>{hi()} がインデントされて @<b>{いない} かチェックしましょう - もしインデントされていたら、関数の一部になってしまっています。関数が呼び出されていません。



次に引数をつかった関数を作ってみましょう。先ほどの例を使います。'hi' という挨拶をする関数に、挨拶をする人の名前をいれてみます。


//emlist[python_intro.py][python]{
def hi(name):
//}


このとおり、関数に @<tt>{name} という引数を足します。


//emlist[python_intro.py][python]{
def hi(name):
    if name == 'Ola':
        print('Hi Ola!')
    elif name == 'Sonja':
        print('Hi Sonja!')
    else:
        print('Hi anonymous!')

hi()
//}


@<tt>{if} 文では @<tt>{print} 関数は４つのスペースでインデントしていましたね。条件式が True のときに print 関数が実行されました。関数の中の if 文で実行する print 関数の前には、上記のように、スペースを８ついれて２回分インデントします。 実行して、どのように動くか見てみましょう。


//cmd[command-line]{
$ python3 python_intro.py
Traceback (most recent call last):
File "python_intro.py", line 10, in <module>
  hi()
TypeError: hi() missing 1 required positional argument: 'name'
//}


おっと、エラーがでてしまいました。 Pythonがエラーメッセージを表示してくれています。 定義した関数 @<tt>{hi()} は、@<tt>{name} という引数が必要ですが、関数を呼び出す時に引数を忘れてしまっています。 最後の行を修正しましょう。


//emlist[python_intro.py][python]{
hi("Ola")
//}


実行してください。


//cmd[command-line]{
$ python3 python_intro.py
Hi Ola!
//}


では、名前を変えてみたらどうなりますか？


//emlist[python_intro.py][python]{
hi("Sonja")
//}


再度実行してください。


//cmd[command-line]{
$ python3 python_intro.py
Hi Sonja!
//}


では、OlaやSonja以外の名前を入れた時、どうなるかわかりますか？やってみて、予測が正しいか確認して下さい。このように出力されましたか。


//cmd[command-line]{
Hi anonymous!
//}


すばらしいですね。 挨拶をする人の名前を変えるたびに繰り返しコードを書く必要がなくなりました。 これが関数を作る理由です。何度も繰り返してコードを書く必要はありません！



もっとスマートなやり方を試してみましょう – ２人以上の名前があり、それぞれに対して条件をつけるのは大変ですよね。


//emlist[python_intro.py][python]{
def hi(name):
    print('Hi ' + name + '!')

hi("Rachel")
//}


では、実行してみましょう。


//cmd[command-line]{
$ python3 python_intro.py
Hi Rachel!
//}


おめでとうございます！関数の書き方を学びましたね！:)


== ループ

//quote{
家で１人でこのパートに挑戦している方へ：このパートは、動画（英語）もあるので参考にしてください。@<href>{https://www.youtube.com/watch?v=aEA6Rc86HF0,Python Basics: For Loop}

//}


さぁ、もう最後のパートですよ。あっという間ですね。 :)



先ほどお話ししたとおり、プログラマーはめんどくさがりで、同じことを繰り返すことは好きではありません。プログラミングはすべてを自動的に処理したい。私たちはすべての人の名前ひとつひとつに対して挨拶をしたくないですよね？こういう時にループが便利です。



リストを覚えていますか？女の子の名前をリストにしてみましょう。


//emlist[python_intro.py][python]{
girls = ['Rachel', 'Monica', 'Phoebe', 'Ola', 'You']
//}


名前を呼んで、全員にあいさつをしてみましょう。@<tt>{hi} 関数が使えますね。ループの中で使いましょう。


//emlist[python_intro.py][python]{
for name in girls:
//}


この @<tt>{for} は @<tt>{if} に似ています。この次に続くコードは、４つスペースを入れる必要があります。



ファイルに書かれるコードはこのようになります。


//emlist[python_intro.py][python]{
def hi(name):
    print('Hi ' + name + '!')

girls = ['Rachel', 'Monica', 'Phoebe', 'Ola', 'You']
for name in girls:
    hi(name)
    print('Next girl')
//}


実行してみましょう。


//cmd[command-line]{
$ python3 python_intro.py
Hi Rachel!
Next girl
Hi Monica!
Next girl
Hi Phoebe!
Next girl
Hi Ola!
Next girl
Hi You!
Next girl
//}


ご覧のとおり、@<tt>{girls} リストのすべての要素に対して、@<tt>{for} の中にインデントして書いたことが繰り返されています。



@<tt>{for} 文では、@<tt>{range} 関数を使って指定した回数だけ繰り返すこともできます。


//emlist[python_intro.py][python]{
for i in range(1, 6):
    print(i)
//}


これを実行すると、次のように出力されます。


//cmd[command-line]{
1
2
3
4
5
//}


@<tt>{range} 関数は、連続する数値を要素とするリストを作ります。引数に指定した開始の数値から終了の数値までのリストです。



2つ目の引数（終了の数値）は、リストに含まれないことに注意してください。 つまり、 @<tt>{range(1, 6)} は、１から５のことであり、６は含まれません。


== まとめ


以上です！@<strong>{おめでとう！頑張りました！} これは簡単ではなかったと思います。自分を褒めてあげてくださいね。ここまで進めることができたのは、本当に素晴らしいことです！



ご参考に、公式の完全なPythonチュートリアルは https://docs.python.org/3/tutorial/ にあります。挑戦するとPythonの理解をもっと深められるでしょう。ここまで頑張りました！



次のチャプターにうつるまえに、少し気晴らしに、ストレッチやお散歩をして、目や身体を休ませてあげてくださいね。



//image[cupcake][]{
//}


