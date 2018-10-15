
= インストール


== 家でチュートリアルに挑戦する方へ


@<href>{https://djangogirls.org/events/,Django Girls のイベント}ではなく、あなたが一人家でこのチュートリアルに挑戦しているのであれば、このチャプターは無視して次のチャプター @<chapref>{how_the_internet_works} に進みましょう。



このチャプターは、インストールに関連する部分を集約してまとめたページです。これらのインストール手順は、以降のチャプターに含まれていますので、そちらを参照してください。 Django Girlsのイベントでは「インストールDay」としてワークショップ前日に、環境設定やインストールをまとめて行っています。ワークショップの都合上、イベント中に環境設定で躓いてしまわないためです。



まとめてインストールする方が都合が良い方は、このチャプターを参照してください。 しかし、いろんなものをパソコンにインストールする前に、一体それらが何なのか学びたい方は、このチャプターを飛ばしてください。これ以降のページでインストールの手順やその説明を行っています。



頑張りましょう！


== インストール


ワークショップに参加してWebサイト（ブログ）を作成する方は、このページの手順に従って、あらかじめ必用なインストールを行っておきましょう。ワークショップ当日はコードを書くことに集中できますよ。


====[column] Chromebook setup (if you're using one)

Chromebookをお持ちでない場合は、このセクションをスキップできます。 もし利用している場合は、普通のインストールの作業とは少し異なります。 インストール手順の残りの部分は無視できます。


===== Cloud 9


Cloud 9 はコードエディタや、インストール、書き込み、およびソフトウェアを実行できるインターネット上で動いているコンピューターへのアクセスを与えるツールです。 チュートリアルをやっている間、Cloud 9はあなたの@<b>{ローカルマシーン}のように動きます。 クラスメートがOS XやUbuntu、Windowsでやっているのと同じようにターミナル上でコマンドを実行していても、あなたのターミナルはCloud 9がセットアップしたどこかのコンピューターにつながっています。

 1. @<href>{https://chrome.google.com/webstore/detail/cloud9/nbdmccoknlfggadpfkmcpnamfnbkmkcp,Chrome ウェブストア}から Cloud 9 を インストールする
 1. @<href>{https://c9.io,C9.io} に行く
 1. アカウントにサインアップします
 1. @<b>{新しいワークスペースを作成}をクリック
 1. 名前は@<b>{django-girls}とします
 1. @<b>{Blank}を選択(下の行の右側から 2 番目のオレンジ色のロゴ)



インターフェイスには、サイドバー、テキストが書かれた大きなメインウィンドウ、下部に小さなウィンドウがあり、次の表示が見えると思います。


//emlist[Cloud 9]{
yourusername:~/workspace $
//}


この下部のエリアはあなたの@<b>{ターミナル}で、Cloud 9 があなたの指示を待っています。ウィンドウサイズを少し大きくすることもできます。


===== 仮想環境


仮想環境 (virtualenvとも呼ばれます) は、取り組んでいるプロジェクト用に、便利なコンピューターコードを詰め込んでおけるプライベートボックスのようなものです。 様々なプロジェクトの様々なコードがプロジェクト間で混ざってしまわないようにこれを使います。



Cloud 9のインターフェイスのうち、下部のターミナルで次を実行します。


//emlist[Cloud 9]{
sudo apt update
sudo apt install python3.6-venv
//}


それでも問題が解決しない場合は、コーチに相談してください。



次に、以下を実行します：


//emlist[Cloud 9]{
mkdir djangogirls
cd djangogirls
python3.6 -mvenv myvenv
source myvenv/bin/activate
pip install django~=2.0.6
//}


(最後の行はチルダに続けてイコール記号をつけることに気をつけてください: ~=)


===== GitHub


@<href>{https://github.com,GitHub}のアカウントを作成しましょう。


===== PythonAnywhere


Django Girlsチュートリアルには、デプロイメントと呼ばれるものに関するセクションが含まれています。これはあなたの新しいWebアプリケーションの原動力となるコードを取得して、それを公にアクセス可能なコンピューター（サーバーと呼ばれます）に移動するプロセスです。これにより、あなたのやったことを他の人が見ることができるようになります。



Chromebookでチュートリアルを行うとき、すでにインターネットに接続されているコンピュータ（ラップトップとは対照的に）を使用しているので、この作業は少し変に思えます。 しかし、Cloud 9のワークスペースを「開発中」の場所、PythonAnywhere をより完成したものを披露する場所として考えると役に立ちます。



したがって、新しいPythonAnywhereアカウントにサインアップしてください。 @<href>{https://www.pythonanywhere.com, www.pythonanywhere.com }


====[/column]


== Pythonのインストール

//quote{
家で１人でこのチャプターに挑戦している方へ：この章は、動画（英語）もあるので参考にしてください。 @<href>{https://www.youtube.com/watch?v=pVTaqzKZCdA,Installing Python & Code Editor}



このセクションはGeek Girls Carrots (https://github.com/ggcarrots/django-carrots) のチュートリアルをベースに作成しました。

//}


Django は、Pythonで開発されています。なにをするにせよ、まずはPythonが必要です。インストールしましょう！ Python 3.6 をインストールします。3.5以前のバージョンをインストール済みの場合は、アップグレードしてください。


====[column] Install Python: Windows


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


====[/column]


====[column] Install Python: OS X


//quote{
@<strong>{注意：} OS XにPythonをインストールする前に、Macの設定でApp Store以外のパッケージをインストールできるようにする必要があります。 「システム環境設定」（「アプリケーション」フォルダ内）に移動し、「セキュリティとプライバシー」、「一般」タブの順にクリックします。 「ダウンロードしたアプリを許可する」が「Mac App Store」に設定されている場合は、「Mac App Storeと識別された開発者」に変更します。
//}


Webサイトからダウンロードしてインストールしましょう。


https://www.python.org/downloads/


 * @<b>{macOS 64-bit/32-bit installer} ファイルをダウンロードしてください。
 * @<b>{python-3.6.5-macosx10.6.pkg}をダブルクリックしてインストーラーを実行してください。


====[/column]


====[column] Install Python: Linux


おそらくほとんどの場合、すぐに使えるPythonがすでにインストールされているでしょう。インストールされているか（とそれがどのバージョンか）を確認するため、コンソールを起動して次のコマンドを打ってください。


//emlist[command-line]{
$ python3 --version
Python 3.6.5
//}


このとき、バージョンの数字の最後が違っていたとしても（例えば、3.6.0など）、アップグレードする必要はありません。 もし、Pythonがインストールされていない場合、あるいはバージョンが古い場合は、次の指示に従ってインストールしてください。


====[/column]


====[column] Install Python: Debian or Ubuntu


次のコマンドをコンソールに打って下さい。


//emlist[command-line]{
$ sudo apt install python3.6
//}


====[/column]


====[column] Install Python: Fedora


次のコマンドをコンソールに打って下さい。


//emlist[command-line]{
$ sudo dnf install python3
//}


古いバージョンのFedoraの場合は、コマンド @<tt>{dnf} が見つからないというエラーが表示されます。その場合は、代わりに yum を使用してください。


====[/column]


====[column] Install Python: openSUSE


次のコマンドをコンソールに打って下さい。


//emlist[command-line]{
$ sudo zypper install python3
//}


====[/column]


インストールされているか確認するために、コマンドプロンプトを開いて次のように@<tt>{Python3}コマンドを入力してください。


//emlist[command-line]{
$ python3 --version
Python 3.6.1
//}


@<strong>{注意：} Windowsをお使いで@<tt>{python3}が見つからないエラーが出る場合、 代わりに@<tt>{python}と入力して、バージョンがPython3.6と出てくるか確認してください。（@<tt>{3}を抜いてみましょう）



分からない時や、質問がある時は、コーチに質問してくださいね。 ときどき上手くいかないこともあります。そんな時は、経験豊富な人に聞くといいですよ。


== コードエディタのインストール


本当にたくさんのエディタがありますが、どれを使うかは、結局は、ほとんど個人の好みの問題です。 ほとんどのPythonプログラマは、PyCharmなど、複雑ですが非常に強力なIDE（統合開発環境）というものを使っています。 しかし、初心者にとってはIDEはそれほど適していないかもしれないので、同じくらい強力で、もっとシンプルなものをオススメします。



オススメのエディタは下記に挙げますが、気軽にコーチに質問して好みや特徴ををきいてみてください。


=== Gedit


Geditはオープン ソースの無料エディタで、すべてのOSで利用可能です。



@<href>{https://wiki.gnome.org/Apps/Gedit#Download,https://wiki.gnome.org/Apps/Gedit#Download}


=== Sublime Text 3


Sublime Textは非常に人気のあるエディタで、無料の試用期間があります。簡単にインストールして使用することができ、すべてのOSに対応しています。



@<href>{https://www.sublimetext.com/3,https://www.sublimetext.com/3}


=== Atom


Atom は、GitHubによる新しいエディタです。無料で、オープンソースで、インストールも使い方も簡単です。Windows、OSX、 Linuxで利用可能です.



@<href>{https://atom.io/,https://atom.io/}


=== なんでコードエディタをインストールするの？


なんでWordやNotepadのようなものを使わず、特別なコードエディタをインストールするのかなと思うかもしれません。



まず、コードは@<strong>{プレーンテキスト}という、何の装飾もない生の文字列でないといけませんが、問題は、WordやTexteditのようなプログラムが生成するのは、実は、プレーンテキストではないということなんです。WordやTexteditは、@<href>{https://en.wikipedia.org/wiki/Rich_Text_Format,RTF（リッチテキストフォーマット）}などのような、改造された形式を使って、フォントや書式を持ったリッチテキストを生成します。



2つ目の理由は、コードエディタは、コードを編集することに特化しているので、コードを意味によって色づけして強調したり、引用符を自動的に閉じたりするような、便利な機能を提供できます。



あとで、こういった動作が全てわかるようになります。すぐに、信頼できる使い古したコードエディタを、お気に入りのツールの一つだと思うようになると思いますよ^^


== virtualenvのセットアップとDjangoのインストール

//quote{
このチャプターの一部はGeek Girls Carrots (https://github.com/ggcarrots/django-carrots) のチュートリアルに基づいています。



このチャプターの一部はCreative Commons Attribution-ShareAlike 4.0 International License のライセンスによる@<href>{http://django-marcador.keimlink.de/,django-marcador tutorial}に基づいています. このdjango-marcador tutorialはMarkus Zapke-Gründemann らが著作権を保有しています。 

//}


=== 仮想環境


Django をインストールする前に、あなたのコーディング環境を、きれいにしておく便利な道具をインストールしてもらいます。 このステップをとばすこともできますが、しかし、このステップをとばすことは全くお勧めしません。 可能な限りベストなセットアップで始めることは将来のたくさんのトラブルからあなたを救うはずですから！



さあ、@<strong>{仮想環境（virtual environment )}(@<b>{virtualenv}とも呼ばれています）を作成してみましょう。 仮想環境（virtual environment）ではプロジェクト単位であなたのPython/Djangoのセットアップを他から隔離します。 これは、あなたがひとつのウェブサイトにおこなったどんな変更も、あなたが開発している他のサイトに影響を及ぼさないということです。 便利でしょ？



あなたがしなければならないのは、あなたが@<tt>{仮想環境（virtual environment）}を作成したいディレクトリを見つけることです（たとえばホームディレクトリなどです）。 Windowsでは、ホームディレクトリは、@<tt>{C:\Users\Name}と書かれているかもしれません (@<tt>{Name}はあなたのログインネームです)。


//quote{
@<strong>{補足：} Windowsの方は、ディレクトリ名に特殊文字やアクセント記号を含まないよう気をつけてください。もし、ユーザー名が特殊文字を含む場合は、@<tt>{C:\djangogirls} のようなディレクトリを作成してください。

//}


このチュートリアルのために、ホームディレクトリに新しいディレクトリ@<tt>{djangogirls}を作成します。


//emlist[command-line]{
$ mkdir djangogirls
$ cd djangogirls
//}


@<tt>{myvenv}という仮想環境（virtual environment）を作成します。一般的なコマンドは以下のようになります：


//emlist[command-line]{
$ python3 -m venv myvenv
//}


====[column] Virtual environment: Windows


新しい@<tt>{virtualenv}を作成するために、コマンドプロンプトを開き（コマンドプロンプトについては何章か前にお話ししましたね。覚えてますか？）、@<tt>{python -m venv myvenv}を実行して下さい。たとえばこのように入力します：


//emlist[command-line]{
C:\Users\Name\djangogirls> python -m venv myvenv
//}


@<tt>{myvenv} というところが、あなたの@<tt>{virtualenv（仮想環境）} の名前です。 どんな名前でも使うことができますが、必ず小文字で表記し、スペース・アクセント記号・特殊文字は入れないでください。 短い名前にしておくのもいいアイデアですーあなたはこの名前を何度も参照しますから！


====[/column]


====[column] Virtual environment: Linux and OS X


LinuxやOS Xで@<tt>{virtualenv}を作るときは、@<tt>{python3 -m venv myvenv}と実行するだけです。 たとえばこんな感じです：


//emlist[command-line]{
$ python3 -m venv myvenv
//}


@<tt>{myvenv} は、あなたの @<tt>{仮想環境(virtualenvironment)} の名前です。 どんな名前でも使うことができますが、必ず小文字で表記し、スペースは入れないでください。 短い名前にしておくのもいいアイデアですーあなたはこの名前を何度も参照しますから！


//quote{
@<strong>{補足：} DebianやUbuntuのバージョンによっては、以下のエラーが出ることがあります。

//}


//emlist[command-line]{
@<seqsplit>{The virtual environment was not created successfully because ensurepip is not available.  On Debian/Ubuntu systems, you need to install the python3-venv package using the following command.}
   apt install python3-venv
@<seqsplit>{You may need to use sudo with that command.  After installing the python3-venv package, recreate your virtual environment.}
//}


//quote{
この場合、エラー内の指示にしたがって、@<tt>{python3-venv}のパッケージをインストールしましょう。
//}


//emlist[command-line]{
$ sudo apt install python3-venv
//}


//quote{
@<strong>{補足：}DebianやUbuntuのバージョンによっては、この仮想環境を実行すると、次のようなエラーがでます。
//}


//emlist[command-line]{
@<seqsplit>{Error: Command '['/home/eddie/Slask/tmp/venv/bin/python3', '-Im', 'ensurepip', '--upgrade', '--default-pip']' returned non-zero exit status 1}
//}


//quote{
このエラーを回避するために、代わりに@<tt>{virtualenv}コマンドを使います。
//}


//emlist[command-line]{
$ sudo apt install python-virtualenv
$ virtualenv --python=python3.6 myvenv
//}


//quote{
@<strong>{補足：}もし以下のようなエラーがでたら、
//}


//emlist[command-line]{
E: Unable to locate package python3-venv
//}


//quote{
代わりに次のコマンドを実行してください。
//}


//emlist[command-line]{
$ sudo apt install python3.6-venv
//}


====[/column]


=== 仮想環境の操作


上に示したコマンドは仮想環境（基本的には一連のディレクトリとファイル）を含む@<tt>{myvenv} という名前（あるいはあなたが選んだ名前）のディレクトリを生成します。次に我々がしたいのは、これを実行し、開始することです。


====[column] Working with virtualenv: Windows


実行して、仮想環境を起動します。


//emlist[command-line]{
C:\Users\Name\djangogirls > myvenv\Scripts\activate
//}


//quote{
@<strong>{補足：}Windows 10では、@<tt>{execution of scripts is disabled on this system}というエラーがWindows PowerShellに出ることがあります。 その場合は、Windows PowerShellを「管理者として開く」で、管理者権限で新しくウィンドウを開いてください。 そして、仮想環境を開始する前に、以下のコマンドを入力してください。

//}


//emlist[command-line]{
C:\WINDOWS\system32> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned
    Execution Policy Change
    @<seqsplit>{The execution policy helps protect you from scripts that you do not trust. Changing the execution policy might expose you to the security risks described in the about_Execution_Policies help topic at http://go.microsoft.com/fwlink/?LinkID=135170. Do you want to change the execution policy? [Y] Yes  [A] Yes to All  [N] No  [L] No to All  [S] Suspend  [?] Help (default is "N"): A}
//}


====[/column]


====[column] Working with virtualenv: Linux and OS X


実行して、仮想環境を起動します。


//emlist[command-line]{
$ source myvenv/bin/activate
//}


@<tt>{myvenv}のところをあながた選んだ@<tt>{仮想環境(virtualenvironment)}名に置き換えることを忘れないで下さいね！


//quote{
@<strong>{備考:} @<tt>{source} ではできない場合もあります。その場合は、代わりに以下のように入力してみてください：

//}


//emlist[command-line]{
$ . myvenv/bin/activate
//}


====[/column]


@<tt>{virtualenv} が起動すると、プロンプトの行頭に@<tt>{(myvenv)}が現れます。



Virtual environment(仮想環境) の中で作業しているとき、@<tt>{python}は自動的に正しいバージョンの@<tt>{Python}を参照しますので、@<tt>{python3}の代わりに@<tt>{python}を使うことができます.



OK,これでDjangoのインストール前に入れておきたい依存関係の準備がすべて整いました。いよいよDjangoのインストールです！


=== Djangoのインストール


今度はあなたの@<tt>{virtualenv}を起動したので、Djangoをインストールすることができます。



これを行う前に、Djangoのインストールに使用する最新バージョンの@<tt>{pip}がインストールされている必要があります。


//emlist[command-line]{
(myvenv) ~$ python3 -m pip install --upgrade pip
//}


==== Requirementsファイルによってパッケージをインストールする


Requirementsファイルは@<tt>{pip install}でインストールするためのパッケージリストが記載されているファイルです:



前にインストールしたコードエディタを使用して、最初に @<tt>{requirements.txt} ファイルを @<tt>{djangogirls/} フォルダーの中に作ります:


//emlist{
djangogirls
└───requirements.txt
//}


@<tt>{djangogirls/requirements.txt} ファイル中に以下のテキストを追加します:


//emlist[djangogirls/requirements.txt]{
Django~=2.0.6
//}


そして、@<tt>{pip install -r requirements.txt} を実行してDjangoをインストールします。


//emlist[command-line]{
(myvenv) ~$ pip install -r requirements.txt
@<seqsplit>{Collecting Django~=2.0.6 (from -r requirements.txt (line 1))}
Downloading Django-2.0.6-py3-none-any.whl (7.1MB)
Installing collected packages: Django
Successfully installed Django-2.0.6
//}


====[column] Installing Django: Windows


//quote{
Windowsでpipを呼んだときにエラーが起きた場合は、あなたのプロジェクトのパス名がスペース・アクセント・特殊文字を含んでいないか確認してみて下さい （例 @<tt>{C:\Users\User Name\djangogirls}）。 もし含まれている場合は、ディレクトリを他のスペース・アクセント・特殊文字が含まれていない場所（@<tt>{C:\djangogirls}など）で作成することを検討してみてください。 新しいディレクトリに新しい仮想環境を作成してから、古いディレクトリを削除して、上記のコマンドを試してください。 （仮想環境のディレクトリは、絶対パスが使われているので、移動させてもうごきません。）
//}


====[/column]


====[column] Installing Django: Windows 8 and Windows 10


//quote{
Djangoをインストールしようとしてコマンドラインがフリーズして動かなくなってしまうことがあります。その時は、以下のコマンドを代わりに入力してみてください。
//}


//emlist[command-line]{
C:\Users\Name\djangogirls> python -m pip install -r requirements.txt
//}


====[/column]


====[column] Installing Django: Linux


//quote{
Ubuntu 12.04でpipを呼んだときにエラーが起きた場合は、仮想環境(virtualenv) 内にpipを再インストールするために@<tt>{python -m pip install -U --force-reinstall pip} を実行して下さい。
//}


====[/column]


以上です！あなたは（ついに）Djangoアプリケーションを作成する準備が整いました！


== Gitのインストール


Gitはたくさんのプログラマが利用する「バージョン管理システム」です。 このソフトウェアは、特定のバージョンを後で呼び出すことができるように、時間の経過とともにファイルへの変更を追跡することができます。 Microsoft Wordの”トラックの変更（track changes)"のようですが、はるかに強力です。


=== Gitのインストール

====[column] Installing Git: Windows


@<href>{https://git-scm.com/,git-scm.com} からGitをダウンロードすることができます。 1つのステップを除いて「次へ」を押して進んで大丈夫です。「PATH環境を調整する(Adjusting your PATH environment)」というステップでは、「WindowsコマンドプロンプトからGitとオプションのUnixツールを使用する(Use Git and optional Unix tools from the Windows Command Prompt)」（一番下の選択肢）を選択します。 それ以外はデフォルトの設定値で構いません。 改行コードの変換(Configuring the line ending conversions)については、「Checkout Windows-style, commit Unix-style line endings」の選択で大丈夫です。



インストールが正常に終了した後、コマンドプロンプトまたはPowerShellを再起動することを忘れないでください。


====[/column]


====[column] Installing Git: OS X


@<href>{https://git-scm.com/,git-scm.com} からGitをダウンロードし、指示に従ってください。


//quote{
@<strong>{注} OS X 10.6、10.7、または10.8を実行している場合は、ここからgitのバージョンをインストールする必要があります: @<href>{https://sourceforge.net/projects/git-osx-installer/files/git-2.3.5-intel-universal-snow-leopard.dmg/download,Git installer for OS X Snow Leopard}

//}


====[/column]


====[column] Installing Git: Debian or Ubuntu


//emlist[command-line]{
$ sudo apt install git
//}


====[/column]


====[column] Installing Git: Fedora


//emlist[command-line]{
$ sudo dnf install git
//}


====[/column]


====[column] Installing Git: openSUSE


//emlist[command-line]{
$ sudo zypper install git
//}


====[/column]


== GitHubのアカウント作成


@<href>{https://www.github.com,GitHub.com}にアクセスし、Sign upを押して無料の新規アカウントを作成してください。


== PythonAnywhereのアカウント作成


PythonAnywhere はクラウド上のサーバーでPythonのコードを走らせるためのサービスです。私たちはこれを私たちのサイトをホスティングして、インターネット上で動かし続けるために使います。



PythonAnywhere で「Beginner」アカウントにサインアップしましょう（クレジットカードのいらない無料利用枠で大丈夫です）。

 * @<href>{https://www.pythonanywhere.com/,https://www.pythonanywhere.com}



//image[pythonanywhere_beginner_account_button][]{
//}



//quote{
@<strong>{注：} ユーザー名を選ぶとき、あなたのブログのURLが@<tt>{あなたのユーザー名.pythonanywhere.com}になることを覚えておいて下さい。ですから、自分のニックネームかあなたのブログが何についてのブログか分かるような名前を選んでみて下さい。

//}

=== PythonAnywhere APIトークンの作成


これはあなたが一度だけ行う必要があるものです。 PythonAnywhere にサインアップしたとき、ダッシュボードページが表示されます。 右上にある「Account」ページへのリンクをクリックし、それから「API Token」タブを選択し、「Create new API token」ボタンをクリックします。



//image[pythonanywhere_create_api_token][]{
//}



== 読んでみよう


お疲れ様でした！これで準備が整いました。ワークショップが始まるまで時間あれば、いくつかのチャプターを読んでおくとよいでしょう。

 * @<chapref>{how_the_internet_works}
 * @<chapref>{intro_to_command_line}
 * @<chapref>{python_introduction}
 * @<chapref>{django}


== ワークショップを楽しんでください！


インストールDayにここまでのインストールが無事に出来た方は、ワークショップでは、@<chapref>{django_start_project}のチャプターからはじめてください。
