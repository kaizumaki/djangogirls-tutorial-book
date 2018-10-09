
= コマンドラインを使ってみよう

//quote{
家で１人でこのチャプターに挑戦している方へ：このチャプターは、動画（英語）もあるので参考にしてください。 @<href>{https://www.youtube.com/watch?v=jvZLWhkzX-8,Your new friend: Command Line}

//}


さぁ、これから最初のコードを書いていきますよ。楽しんでいきましょう！:)



@<strong>{最初にお友達になるのはコレです。: コマンドライン!}



プログラマーが黒い画面に向かっている光景を見たことがありますか？ここからは、その黒い画面を触ってみます。最初はちょっとコワイと思うかもしれませんが、そんなことはありません。プロンプトと呼ばれるものがあなたの命令（コマンド）を待っています。


//quote{
@<strong>{備考：} このチュートリアルでは、”ディレクトリ”や"フォルダ"という用語が出てきますが、同じ意味です。

//}

== コマンドラインって何？


さて、@<strong>{コマンドライン} あるいは @<strong>{コマンドライン インターフェイス}と呼ばれるこの画面は、キーボードで入力したテキストで命令を出してコンピューターと直接対話するように、ファイルを見たり、変更したりするものです。 グラフィカル・インターフェイスではないだけで、WindowsのエクスプローラやMacのFinderと同じ役割です。 このコマンドラインは、 @<b>{cmd}や@<b>{CLI}、@<b>{プロンプト}、@<b>{コンソール}、@<b>{ターミナル}と呼ばれることもあります.


== コマンドラインインタフェースを開く


では、実際にコマンドラインを開いて、触ってみることとしましょう。


====[column] Opening: Windows


［スタート］→［Windowsシステムツール］→［コマンドプロンプト］を選択しましょう


@<strong>{備考：} Windowsの古いバージョンの場合、[スタート] → [アクセサリ] → [コマンドプロンプト] です。


====[/column]


====[column] Opening: OS X


［アプリケーション］→［ユーティリティ］→［ターミナル］を選択しましょう。


====[/column]


====[column] Opening: Linux


おそらく ［アプリケーション］→［アクセサリ］→［ターミナル］と選択し起動できるでしょう。あなたのシステムによってはこの通りではないことがあります。見つからないときは、Google先生にきいてみましょう. :)


====[/column]


== プロンプト


おそらく今、真っ白または真っ黒な画面が開かれていることでしょう。この画面はあなたの命令を待っています。


====[column] Prompt: OS X and Linux


MacあるいはLinuxの方は、次のように @<tt>{$} と表示されているのがわかりますか？


//cmd[command-line]{
$
//}


====[/column]


====[column] Prompt: Windows


Windowsの方は、 @<tt>{>} という記号が表示されていることでしょう。


//cmd[command-line]{
>
//}


====[/column]


各コマンドの先頭には、この記号とスペースがつきます。あなたのコンピューターが表示してくれるので、自分で入力する必要はありません. :)


//quote{
ちょっと補足です。プロンプト記号の前に @<tt>{C:\Users\ola>} や @<tt>{Olas-MacBook-Air:~ ola$} のような表示がありますね。これは間違いではありません。100%正解です。このチュートリアルでは、シンプルにわかりやすくするために、その部分を省略して記述します。

//}


@<tt>{$} や @<tt>{>} と書かれているところまでを、 @<b>{コマンドラインプロンプト} あるいは略して@<b>{プロンプト}と呼ばれます。プロンプトは、あなたがここに何かを入力することを促しています。



このチュートリアルでは、コマンドを入力してほしい時は、 @<tt>{$} や @<tt>{>} を含めて示しています。 $や>は無視して、プロンプト以降のコマンドを入力してください。


== 最初のコマンド (イェイ！)


次のようにコマンドを入力してみましょう。:


====[column] Your first command: OS X and Linux


//cmd[command-line]{
$ whoami
//}


====[/column]


====[column] Your first command: Windows


//cmd[command-line]{
> whoami
//}


====[/column]


そして最後にEnterキーを押して下さい。このような結果が返ってきます


//cmd[command-line]{
$ whoami
olasitarska
//}


ご覧のとおり、コンピューターがあなたのユーザーネームを表示してくれましたね。面白いでしょ? :)


//quote{
コピー＆ペーストではなく、コマンドを入力して試してみてください。そのうち自然と覚えられるようになりますからね！

//}


== 基本


OSによってコマンドが若干違います。あなたのコンピューターのOSの方法に従って、以下は進めていってくださいね。次にいってみましょう。


=== カレントディレクトリ（現在のディレクトリ）


今どこのディレクトリにいるか（どのフォルダで作業をしているか）、知りたいですよね？では、このようにキーボードで入力して、@<tt>{Enterキー}をおしてください。


====[column] Current directory: OS X and Linux


//cmd[command-line]{
$ pwd
/Users/olasitarska
//}


//quote{
補足: 'pwd' は'print working directory'を意味しており、現在いる作業ディレクトリを取得することです。

//}


====[/column]


====[column] Current directory: Windows


//cmd[command-line]{
> cd
C:\Users\olasitarska
//}


//quote{
補足: 'cd' は、'change directory' を意味しています。Powershellを使うと、LinuxやMac OS Xのようにpwdコマンドを使えます。

//}


====[/column]


おそらく、似たようなものがあなたの画面に表示されたのではないでしょうか。コマンドラインを起動した最初は、通常ユーザーのホームディレクトリが表示されます。


=== ファイルとディレクトリの一覧


では、その中には何があるのでしょうか？表示させてみましょう。


====[column] List files and directories: OS X and Linux


//cmd[command-line]{
$ ls
Applications
Desktop
Downloads
Music
...

//}


====[/column]


====[column] List files and directories: Windows


//cmd[command-line]{
> dir
 Directory of C:\Users\olasitarska
05/08/2014 07:28 PM <DIR>      Applications
05/08/2014 07:28 PM <DIR>      Desktop
05/08/2014 07:28 PM <DIR>      Downloads
05/08/2014 07:28 PM <DIR>      Music
...

//}

//quote{
補足：Powershellでは、lsコマンドをLinux や Mac OS X同様に使えます。

//}


====[/column]


=== カレントディレクトリの変更


次に、デスクトップのディレクトリに移動してみましょう。


====[column] Change current directory: OS X and Linux


//cmd[command-line]{
$ cd Desktop
//}


====[/column]


====[column] Change current directory: Windows


//cmd[command-line]{
> cd Desktop
//}


====[/column]


本当に変更されたかどうか確認してみてください：


====[column] Check if changed: OS X and Linux


//cmd[command-line]{
$ pwd
/Users/olasitarska/Desktop
//}


====[/column]


====[column] Check if changed: Windows


//cmd[command-line]{
> cd
C:\Users\olasitarska\Desktop
//}


====[/column]


できていますね！


//quote{
PRO tip: @<tt>{cd D}と入力して、キーボードの@<tt>{tab}ボタンを押してください。すると、Dに続く残りの部分が自動的に補完されて入力されます。 もし、Dから始まるディレクトリ名が他にもあれば、@<tt>{tabボタン}を繰り返し押すと候補が次々と表示されます。入力が楽になりますね。

//}


=== ディレクトリの作成


それでは、Django Girlsのディレクトリをデスクトップに新規作成してみましょう。


====[column] Create directory: OS X and Linux


//cmd[command-line]{
$ mkdir practice
//}


====[/column]


====[column] Create directory: Windows


//cmd[command-line]{
> mkdir practice
//}


====[/column]


この短いコマンドで、デスクトップにpracticeという名前の新しいフォルダが作成されました。 あなたのデスクトップを見てフォルダが作成されていることを確認してみましょう。あるいは、先ほど学んだコマンド @<tt>{ls} や @<tt>{dir} を使って確認しましょう。 やってみてください。 :)


//quote{
PRO tip: 同じコマンドを何度もなんども入力したくない時は、上下矢印キー@<tt>{↑}、@<tt>{↓}を押せば、先ほどキーボードから入力したものが現れます。内容を修正したい場合には，左右矢印キー←，→を利用して修正したい位置にカーソルを移動させて，修正することができますよ。

//}


=== エクササイズ！


練習をしてみましょう。先ほど作成した@<tt>{practice}ディレクトリの中に、新たに@<tt>{test}という名前のディレクトリを作成してください。（使うコマンドは、@<tt>{cd}と @<tt>{mkdir} ですよ。）


==== 解答:


====[column] Exercise solution: OS X and Linux


//cmd[command-line]{
$ cd practice
$ mkdir test
$ ls
test
//}


====[/column]


====[column] Exercise solution: Windows


//cmd[command-line]{
> cd practice
> mkdir test
> dir
05/08/2014 07:28 PM <DIR>      test
//}


====[/column]


おめでとうございます！よくできました！


=== クリーンアップ


練習がおわったら、それをそのままに置いておくと邪魔になりますね。削除しておきましょう。



はじめに、作業するディレクトリをデスクトップに戻しましょう。


====[column] Clean up: OS X and Linux


//cmd[command-line]{
$ cd ..
//}


====[/column]


====[column] Clean up: Windows


//cmd[command-line]{
> cd ..
//}


====[/column]


@<tt>{cd} の後にある@<tt>{..} で、現在の親ディレクトリに移動します。（今作業しているフォルダのひとつ上のフォルダに移動するということですね。）



現在の作業ディレクトリを確認しておきましょう。


====[column] Check location: OS X and Linux


//cmd[command-line]{
$ pwd
/Users/olasitarska/Desktop
//}


====[/column]


====[column] Check location: Windows


//cmd[command-line]{
> cd
C:\Users\olasitarska\Desktop
//}


====[/column]


では、practiceディレクトリを削除しましょう。


//quote{
*@<b>{注意！: *}　@<tt>{del}や @<tt>{rmdir}、@<tt>{rm} のコマンドを使って削除したファイルは、復活できません。完全に消えてしまいます。 このコマンドを使う時は、よく気をつけてくださいね。

//}


====[column] Delete directory: Windows Powershell、OS X and Linux


//cmd[command-line]{
$ rm -r practice
//}


====[/column]


====[column] Delete directory: Windows Command Prompt


//cmd[command-line]{
> rmdir /S practice
practice, Are you sure <Y/N>? Y
//}


====[/column]


できました! 本当に削除されたか、確認してみましょう。:


====[column] Check deletion: OS X and Linux


//cmd[command-line]{
$ ls
//}


====[/column]


====[column] Check deletion: Windows


//cmd[command-line]{
> dir
//}


====[/column]


=== 終了


ここまでです。それではコマンドラインを終了しましょう。かっこいいやり方で終わりたいですよね? :)


====[column] Exit: OS X and Linux


//cmd[command-line]{
$ exit
//}


====[/column]


====[column] Exit: Windows


//cmd[command-line]{
> exit
//}


====[/column]


かっこいいですね? :)


== まとめ


ここに学んだコマンドをまとめておきます。

//tsize[15,15,35,35]
//table[tbl1][]{
コマンド (Windows)	コマンド (Mac OS / Linux)	説明	例
-----------------
exit	exit	ウインドウを閉じる	@<strong>{exit}
cd	cd	ディレクトリを変更	@<strong>{cd test}
cd	pwd	現在のディレクトリを表示	@<strong>{cd} (Windows) or @<strong>{pwd} (Mac OS / Linux)
dir	ls	ディレクトリ/ファイルの一覧を表示	@<strong>{dir}
copy	cp	ファイルのコピー	@<strong>{copy c:\test\test.txt c:\windows\test.txt}
move	mv	ファイルを移動	@<strong>{move c:\test\test.txt c:\windows\test.txt}
mkdir	mkdir	新しいディレクトリを作成	@<strong>{mkdir testdirectory}
rmdir (or del)	rm	ファイルを削除	@<strong>{del c:\test\test.txt}
rmdir /S	rm -r	ディレクトリを削除	@<strong>{rm -r testdirectory}
//}


ここで勉強したのはコマンドのほんの一部でしたが、このワークショップで使うコマンドはこれだけです。



もっと勉強したい方は、@<href>{http://ss64.com,ss64.com} に各OSのコマンド一覧があります。ご参考までに。


== 準備OK？


よし、次はPythonを勉強していきましょう!
