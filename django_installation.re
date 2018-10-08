
= Djangoのインストール

//quote{
@<strong>{補足：} Chromebookを使っている方は、このチャプターは飛ばして、 @<chapref>{chromebook_setup} の説明に従ってセットアップしてください。



@<strong>{補足：} インストールのチャプターで既にインストール済みの方は、このチャプターは飛ばして次に進みましょう。



このチャプターの一部はGeek Girls Carrots (https://github.com/ggcarrots/django-carrots) のチュートリアルに基づいています。



このチャプターの一部はCreative Commons Attribution-ShareAlike 4.0 International License のライセンスによる@<href>{http://django-marcador.keimlink.de/,django-marcador tutorial}に基づいています. このdjango-marcador tutorialはMarkus Zapke-Gründemann らが著作権を保有しています。 

//}

== 仮想環境


Django をインストールする前に、あなたのコーディング環境を、きれいにしておく便利な道具をインストールしてもらいます。 このステップをとばすこともできますが、しかし、このステップをとばすことは全くお勧めしません。 可能な限りベストなセットアップで始めることは将来のたくさんのトラブルからあなたを救うはずですから！



さあ、@<strong>{仮想環境（virtual environment )}(@<b>{virtualenv}とも呼ばれています）を作成してみましょう。 仮想環境（virtual environment）ではプロジェクト単位であなたのPython/Djangoのセットアップを他から隔離します。 これは、あなたがひとつのウェブサイトにおこなったどんな変更も、あなたが開発している他のサイトに影響を及ぼさないということです。 便利でしょ？



あなたがしなければならないのは、あなたが@<tt>{仮想環境（virtual environment）}を作成したいディレクトリを見つけることです（たとえばホームディレクトリなどです）。 Windowsでは、ホームディレクトリは、@<tt>{C:\Users\Name}と書かれているかもしれません (@<tt>{Name}はあなたのログインネームです)。


//quote{
@<strong>{補足：} Windowsの方は、ディレクトリ名に特殊文字やアクセント記号を含まないよう気をつけてください。もし、ユーザー名が特殊文字を含む場合は、@<tt>{C:\djangogirls} のようなディレクトリを作成してください。

//}


このチュートリアルのために、ホームディレクトリに新しいディレクトリ@<tt>{djangogirls}を作成します。


//cmd{
$ mkdir djangogirls
$ cd djangogirls
//}


@<tt>{myvenv}という仮想環境（virtual environment）を作成します。一般的なコマンドは以下のようになります：


//cmd{
$ python3 -m venv myvenv
//}


//panelsection[Virtual environment: Windows]{


新しい@<tt>{virtualenv}を作成するために、コマンドプロンプトを開き（コマンドプロンプトについては何章か前にお話ししましたね。覚えてますか？）、@<tt>{python -m venv myvenv}を実行して下さい。たとえばこのように入力します：


//}


//cmd{
C:\Users\Name\djangogirls> python -m venv myvenv
//}


//panelsection[]{


@<tt>{myvenv} というところが、あなたの@<tt>{virtualenv（仮想環境）} の名前です。 どんな名前でも使うことができますが、必ず小文字で表記し、スペース・アクセント記号・特殊文字は入れないでください。 短い名前にしておくのもいいアイデアですーあなたはこの名前を何度も参照しますから！


//}


//panelsection[Virtual environment: Linux and OS X]{


LinuxやOS Xで@<tt>{virtualenv}を作るときは、@<tt>{python3 -m venv myvenv}と実行するだけです。 たとえばこんな感じです：


//}


//cmd{
$ python3 -m venv myvenv
//}


//panelsection[]{


@<tt>{myvenv} は、あなたの @<tt>{仮想環境(virtualenvironment)} の名前です。 どんな名前でも使うことができますが、必ず小文字で表記し、スペースは入れないでください。 短い名前にしておくのもいいアイデアですーあなたはこの名前を何度も参照しますから！


//}


//quote{
@<strong>{補足：} DebianやUbuntuのバージョンによっては、以下のエラーが出ることがあります。

//}


//cmd{
@<seqsplit>{The virtual environment was not created successfully because ensurepip is not available.  On Debian/Ubuntu systems, you need to install the python3-venv package using the following command.}
   apt install python3-venv
@<seqsplit>{You may need to use sudo with that command.  After installing the python3-venv package, recreate your virtual environment.}
//}


//panelsection[]{


この場合、エラー内の指示にしたがって、@<tt>{python3-venv}のパッケージをインストールしましょう。


//}


//cmd{
$ sudo apt install python3-venv
//}


//panelsection[]{


@<strong>{補足：}DebianやUbuntuのバージョンによっては、この仮想環境を実行すると、次のようなエラーがでます。


//}


//cmd{
@<seqsplit>{Error: Command '['/home/eddie/Slask/tmp/venv/bin/python3', '-Im', 'ensurepip', '--upgrade', '--default-pip']' returned non-zero exit status 1}
//}


//panelsection[]{


このエラーを回避するために、代わりに@<tt>{virtualenv}コマンドを使います。


//}


//cmd{
$ sudo apt install python-virtualenv
$ virtualenv --python=python3.6 myvenv
//}


//panelsection[]{


@<strong>{補足：}もし以下のようなエラーがでたら、


//}


//cmd{
E: Unable to locate package python3-venv
//}


//panelsection[]{


代わりに次のコマンドを実行してください。


//}


//cmd{
sudo apt install python3.6-venv
//}


== 仮想環境の操作


上に示したコマンドは仮想環境（基本的には一連のディレクトリとファイル）を含む@<tt>{myvenv} という名前（あるいはあなたが選んだ名前）のディレクトリを生成します。次に我々がしたいのは、これを実行し、開始することです。


//panelsection[Working with virtualenv: Windows]{


実行して、仮想環境を起動します。


//}


//cmd{
C:\Users\Name\djangogirls > myvenv\Scripts\activate
//}


//quote{
@<strong>{補足：}Windows 10では、@<tt>{execution of scripts is disabled on this system}というエラーがWindows PowerShellに出ることがあります。 その場合は、Windows PowerShellを「管理者として開く」で、管理者権限で新しくウィンドウを開いてください。 そして、仮想環境を開始する前に、以下のコマンドを入力してください。

//}


//cmd{
C:\WINDOWS\system32> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned
    Execution Policy Change
    @<seqsplit>{The execution policy helps protect you from scripts that you do not trust. Changing the execution policy might expose you to the security risks described in the about_Execution_Policies help topic at http://go.microsoft.com/fwlink/?LinkID=135170. Do you want to change the execution policy? [Y] Yes  [A] Yes to All  [N] No  [L] No to All  [S] Suspend  [?] Help (default is "N"): A}
//}


//panelsection[Working with virtualenv: Linux and OS X]{


実行して、仮想環境を起動します。


//}


//cmd{
$ source myvenv/bin/activate
//}


//panelsection[]{


@<tt>{myvenv}のところをあながた選んだ@<tt>{仮想環境(virtualenvironment)}名に置き換えることを忘れないで下さいね！


//}


//quote{
@<strong>{備考:} @<tt>{source} ではできない場合もあります。その場合は、代わりに以下のように入力してみてください：

//}


//cmd{
$ . myvenv/bin/activate
//}


@<tt>{virtualenv} が起動すると、プロンプトの行頭に@<tt>{(myvenv)}が現れます。



Virtual environment(仮想環境) の中で作業しているとき、@<tt>{python}は自動的に正しいバージョンの@<tt>{Python}を参照しますので、@<tt>{python3}の代わりに@<tt>{python}を使うことができます.



OK,これでDjangoのインストール前に入れておきたい依存関係の準備がすべて整いました。いよいよDjangoのインストールです！


== Djangoのインストール


今度はあなたの@<tt>{virtualenv}を起動したので、Djangoをインストールすることができます。



これを行う前に、Djangoのインストールに使用する最新バージョンの@<tt>{pip}がインストールされている必要があります。


//cmd{
(myvenv) ~$ python3 -m pip install --upgrade pip
//}


=== Requirementsファイルによってパッケージをインストールする


Requirementsファイルは@<tt>{pip install}でインストールするためのパッケージリストが記載されているファイルです:



前にインストールしたコードエディタを使用して、最初に @<tt>{requirements.txt} ファイルを @<tt>{djangogirls/} フォルダーの中に作ります:


//emlist{
djangogirls
└───requirements.txt
//}


@<tt>{djangogirls/requirements.txt} ファイル中に以下のテキストを追加します:


//emlist[djangogirls/requirements.txt]{
Django~={{ book.django_version }}
//}


そして、@<tt>{pip install -r requirements.txt} を実行してDjangoをインストールします。


//cmd{
(myvenv) ~$ pip install -r requirements.txt
@<seqsplit>{Collecting Django~={{ book.django_version }\} (from -r requirements.txt (line 1))}
Downloading Django-{{ book.django_version }}-py3-none-any.whl (7.1MB)
Installing collected packages: Django
Successfully installed Django-{{ book.django_version }}
//}


//panelsection[Installing Django: Windows]{


Windowsでpipを呼んだときにエラーが起きた場合は、あなたのプロジェクトのパス名がスペース・アクセント・特殊文字を含んでいないか確認してみて下さい （例 @<tt>{C:\Users\User Name\djangogirls}）。 もし含まれている場合は、ディレクトリを他のスペース・アクセント・特殊文字が含まれていない場所（@<tt>{C:\djangogirls}など）で作成することを検討してみてください。 新しいディレクトリに新しい仮想環境を作成してから、古いディレクトリを削除して、上記のコマンドを試してください。 （仮想環境のディレクトリは、絶対パスが使われているので、移動させてもうごきません。）


//}


//panelsection[Installing Django: Windows 8 and Windows 10]{


Djangoをインストールしようとしてコマンドラインがフリーズして動かなくなってしまうことがあります。その時は、以下のコマンドを代わりに入力してみてください。


//}


//cmd{
C:\Users\Name\djangogirls> python -m pip install -r requirements.txt
//}


//panelsection[Installing Django: Linux]{


Ubuntu 12.04でpipを呼んだときにエラーが起きた場合は、仮想環境(virtualenv) 内にpipを再インストールするために@<tt>{python -m pip install -U --force-reinstall pip} を実行して下さい。


//}


以上です！あなたは（ついに）Djangoアプリケーションを作成する準備が整いました！
