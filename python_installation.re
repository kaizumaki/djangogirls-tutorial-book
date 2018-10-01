
= Pythonをはじめよう


ついにここまで来ましたね！



まずは、最初にPythonとは何かお話させて下さい。Pythonはとても人気のあるプログラミング言語です。Webサイトや、ゲーム、サイエンス、グラッフィックス、などなど、たくさんの場面で使われています。



Pythonは1980年台の終わりに、人間が読みやすい（機械だけでなく）言語を目的に開発されました。 だから、他の言語に比べて、Pythonはとてもシンプルで、勉強しやすいのです。でもご心配なく、Pythonはとってもパワフルな言語ですから！


= Pythonのインストール

//quote{
@<strong>{注意：}Chromebookをお使いの場合、このチャプターは飛ばして、@<href>{../chromebook_setup/README.md,Chromebookのセットアップ}の章をすすめてください。



@<strong>{注意：}すでにインストール手順を実行している場合は、これをもう一度行う必要はありません。次の章に進んでください。



家で１人でこのチャプターに挑戦している方へ：この章は、動画（英語）もあるので参考にしてください。 @<href>{https://www.youtube.com/watch?v=pVTaqzKZCdA,Installing Python & Code Editor}



このセクションはGeek Girls Carrots (https://github.com/ggcarrots/django-carrots) のチュートリアルをベースに作成しました。

//}


Django は、Pythonで開発されています。なにをするにせよ、まずはPythonが必要です。インストールしましょう！ Python 3.6 をインストールします。3.5以前のバージョンをインストール済みの場合は、アップグレードしてください。


//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--sec data-title="Install Python: Windows" data-id="python_windows" data-collapse=true ces-->
//}


Windowsをお使いのかたは、まずシステム情報を開き、システムの種類が32-bitバージョンか64-bitバージョンかを確認します（システム情報の開き方：Windowsキー + Pause/Break キー　もしくは　コントロールパネル＞システムとセキュリティ＞システムを開く）。 Python for Windowsは、https://www.python.org/downloads/windows/ からダウンロードできます。 「Latest Python 3 Release - Python x.x.x」のリンクをクリックしてください。 お使いのコンピュータが@<strong>{64ビット}版のWindowsを実行している場合は、@<strong>{Windows x86-64 executable installer}をダウンロードしてください。 32ビット版の場合は、@<strong>{Windows x86 executable installer}をダウンロードします。 インストーラをダウンロードしたら、それを実行して（ダブルクリックして）インストーラの指示に従ってください。



@<strong>{インストール時に必ず「Add Python 3.6 to PATH」にチェックをいれましょう}：



//image[python-installation-options][Pythonのパスを通すのを忘れないようにしてください。]{
//}




次のステップでは、Windowsコマンドラインを使用します（コマンドラインについては後ほど詳しく教えます）。 現時点では、コマンドを入力する必用がある場合、スタートメニューから検索フィールドに「コマンドプロンプト」入力してください。 （Windwosのバージョンが古い場合、「スタートメニュー」をクリックして、表示されるアプリ一覧から「Windowsシステムツール」を選んで、「コマンドプロンプト」をクリックしてください。）あるいは、「Windowsキー」を押しながら「R」キーを押すと、「ファイル名を指定して実行」が現れます。 コマンドプロンプトを開くには、そこに "cmd" と入力してenterキーを押します。



//image[windows-plus-r]["ファイル名を指定して実行"で、"cmd"と入力してください]{
//}




注意：古いバージョンのWindows（7、Vista、またはそれ以前のバージョン）を使用していて、Python 3.6.xインストーラがエラーで失敗した場合、次のいずれかを試みることができます：

 1. すべてのWindowsアップデートをインストールして、Python 3.6を再インストールしてみる。
 1. @<href>{https://www.python.org/downloads/windows/,古いバージョンのPython}をインストールしてみる。例えば@<href>{https://www.python.org/downloads/release/python-346/,3.4.6}。



古いバージョンのPythonをインストールする場合、インストール画面は上記のものとは多少異なる場合があります。 下にスクロールして「Add python.exe to Path」のところを左クリックして「Will be installed on local hard drive（ローカルハードドライブにインストールされます）」を選択してください：



//image[add_python_to_windows_path][古いバージョンのパスを追加してください]{
//}



//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--endsec-->
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--sec data-title="Install Python: OS X" data-id="python_OSX"
data-collapse=true ces-->
//}

//quote{
@<strong>{注意}：OS XにPythonをインストールする前に、Macの設定でApp Store以外のパッケージをインストールできるようにする必要があります。 「システム環境設定」（「アプリケーション」フォルダ内）に移動し、「セキュリティとプライバシー」、「一般」タブの順にクリックします。 「ダウンロードしたアプリを許可する」が「Mac App Store」に設定されている場合は、「Mac App Storeと識別された開発者」に変更します。

//}


Webサイトからダウンロードしてインストールしましょう。 https://www.python.org/downloads/

 * @<b>{macOS 64-bit/32-bit installer} ファイルをダウンロードしてください。
 * @<b>{python-3.6.5-macosx10.6.pkg}をダブルクリックしてインストーラーを実行してください。


//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--endsec-->
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--sec data-title="Install Python: Linux" data-id="python_linux"
data-collapse=true ces-->
//}


おそらくほとんどの場合、すぐに使えるPythonがすでにインストールされているでしょう。インストールされているか（とそれがどのバージョンか）を確認するため、コンソールを起動して次のコマンドを打ってください。



{% filename %}command-line{% endfilename %}


//emlist{
$ python3 --version
Python 3.6.5
//}


このとき、バージョンの数字の最後が違っていたとしても（例えば、3.6.0など）、アップグレードする必要はありません。 もし、Pythonがインストールされていない場合、あるいはバージョンが古い場合は、次の指示に従ってインストールしてください。


//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--endsec-->
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--sec data-title="Install Python: Debian or Ubuntu" data-id="python_debian" data-collapse=true ces-->
//}


次のコマンドをコンソールに打って下さい。



{% filename %}command-line{% endfilename %}


//emlist{
$ sudo apt install python3.6
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--endsec-->
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--sec data-title="Install Python: Fedora" data-id="python_fedora"
data-collapse=true ces-->
//}


次のコマンドをコンソールに打って下さい。



{% filename %}command-line{% endfilename %}


//emlist{
$ sudo dnf install python3
//}


古いバージョンのFedoraの場合は、コマンド @<tt>{dnf} が見つからないというエラーが表示されます。その場合は、代わりに yum を使用してください。


//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--endsec-->
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--sec data-title="Install Python: openSUSE" data-id="python_openSUSE"
data-collapse=true ces-->
//}


次のコマンドをコンソールに打って下さい。



{% filename %}command-line{% endfilename %}


//emlist{
$ sudo zypper install python3
//}

//emlist{
XXX: BLOCK_HTML: YOU SHOULD REWRITE IT
<!--endsec-->
//}


インストールされているか確認するために、コマンドプロンプトを開いて次のように@<tt>{Python3}コマンドを入力してください。



{% filename %}command-line{% endfilename %}


//emlist{
$ python3 --version
Python 3.6.1
//}


@<strong>{注意：} Windowsをお使いで@<tt>{python3}が見つからないエラーが出る場合、 代わりに@<tt>{python}と入力して、バージョンがPython3.6と出てくるか確認してください。（@<tt>{3}を抜いてみましょう）


//hr


分からない時や、質問がある時は、コーチに質問してくださいね。 ときどき上手くいかないこともあります。そんな時は、経験豊富な人に聞くといいですよ。

