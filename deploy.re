
= デプロイ！

//quote{
@<strong>{補足} このチャプターはちょっと難しいことが沢山書かれています。 頑張って最後までやりきってください。デプロイはウェブサイトを開発するプロセスの上で、とても重要な部分ですが、つまずきやすいポイントも多く含まれています。 チュートリアルの途中にこのチャプターを入れています。そういったつまずきやすい箇所はメンターに質問して、あなたが作っているウェブサイトをオンラインでみれるようにしてください。 言い換えれば、もし時間切れでワークショップ内でチュートリアルを終わらせることができなかったとしても、この後のチュートリアルはきっと自分で終わらせることができるでしょう。

//}


今のところ、あなたが作ったサイトは、あなたのコンピューターでしかみることができません。 ここでは、デプロイの方法を学びましょう！ デプロイとは、あなたが作っているアプリケーションをインターネットで公開することです。あなた以外の人もウェブサイトを見ることができるようになりますよ. :)



これまでに学んだとおり、ウェブサイトはサーバーに置かれています。 インターネットで利用できる多くのサーバー プロバイダーがありますが、私達は @<href>{https://www.pythonanywhere.com/,PythonAnywhere} を使用します。 PythonAnywhere は、多くの人がアクセスするものではない小さいアプリケーションを無料で公開できますので今のあなたには最適でしょう。



使用するその他の外部サービスは @<href>{https://www.github.com,GitHub}、コードのホスティング サービスです。 他にも色々ありますが、ほとんどのプログラマはGitHubのアカウントを持っています。そしてあなたも今そうなります。



これら3つの場所が重要になります。 ローカルコンピューターは、開発およびテストを行う場所になります。 変更に満足したら、GitHub上にプログラムのコピーを配置します。 あなたのウェブサイトはPythonAnywhereで公開され、GitHub からコードの新しいコピーを取得することによって更新されます。


== Git

//quote{
@<strong>{注：}もし、すでにインストールしていた場合は再度行う必要はありません。次のセクションに進んであなたのGitリポジトリを作り始められます。

//}


Gitはたくさんのプログラマが利用する「バージョン管理システム」です。 このソフトウェアは、特定のバージョンを後で呼び出すことができるように、時間の経過とともにファイルへの変更を追跡することができます。 Microsoft Wordの”トラックの変更（track changes)"のようですが、はるかに強力です。


=== Gitのインストール


//panelsection[Installing Git: Windows]{


@<href>{https://git-scm.com/,git-scm.com} からGitをダウンロードすることができます。 1つのステップを除いて「次へ」を押して進んで大丈夫です。「PATH環境を調整する(Adjusting your PATH environment)」というステップでは、「WindowsコマンドプロンプトからGitとオプションのUnixツールを使用する(Use Git and optional Unix tools from the Windows Command Prompt)」（一番下の選択肢）を選択します。 それ以外はデフォルトの設定値で構いません。 改行コードの変換(Configuring the line ending conversions)については、「Checkout Windows-style, commit Unix-style line endings」の選択で大丈夫です。



インストールが正常に終了した後、コマンドプロンプトまたはPowerShellを再起動することを忘れないでください。


//}


//panelsection[Installing Git: OS X]{


@<href>{https://git-scm.com/,git-scm.com} からGitをダウンロードし、指示に従ってください。


//}


//quote{
@<strong>{注} OS X 10.6,10.7、または10.8を実行している場合は、ここからgitのバージョンをインストールする必要があります: @<href>{https://sourceforge.net/projects/git-osx-installer/files/git-2.3.5-intel-universal-snow-leopard.dmg/download,Git installer for OS X Snow Leopard}

//}


//codepanelsection[Installing Git: Debian or Ubuntu]{


$ sudo apt install git


//}


//codepanelsection[Installing Git: Fedora]{


$ sudo dnf install git


//}


//codepanelsection[Installing Git: openSUSE]{


$ sudo zypper install git


//}


=== Gitリポジトリを始める


Gitはコードリポジトリ（または略して「リポジトリ」）というものの中に置かれる特定のファイルへの変更を追跡します。 私たちのプロジェクトを開始しましょう。 あなたのコンソールを開き、@<tt>{djangogirls} ディレクトリでこれらのコマンドを実行します。


//quote{
@<strong>{備考：}リポジトリを初期化する前に @<tt>{pwd} (OSX/Linux) または @<tt>{cd} (Windows) コマンドで現在の作業ディレクトリを確認してください。 @<tt>{djangogirls} フォルダー内にいる必要があります。

//}


//cmd{
$ git init
Initialized empty Git repository in ~/djangogirls/.git/
$ git config --global user.name "Your Name"
$ git config --global user.email you@example.com
//}


gitリポジトリを初期化することは、プロジェクトごとに1回だけ行う必要があります（ユーザー名と電子メールをもう一度入力する必要はありません）。



Git はこのディレクトリ内のすべてのファイルとフォルダの変更を追跡しますが、無視してほしいいくつかのファイルがあります。 ベースディレクトリ内で @<tt>{.gitignore} という名前のファイルを作成することによってこれを行います。 あなたのエディターを開き、次の内容で新しいファイルを作成します。


//emlist[.gitignore]{
*.pyc
*~
__pycache__
myvenv
db.sqlite3
/static
.DS_Store
//}


これを "djangogirls" フォルダ内に @<tt>{.gitignore} という名前で保存します。


//quote{
@<strong>{備考：}ファイル名の先頭のドットは重要です! もしそのファイルを作るのが難しいなら、（Macをお使いの方はFinderからドット（ . ）で始まるファイルを作れません。）そういう時はエディタでSave Asから作成すれば問題ありません。



@<strong>{備考：} @<tt>{.gitignore}ファイルで指定したファイルの1つが@<tt>{db.sqlite3}です。 そのファイルはローカルデータベースで、すべての投稿が保存されます。 PythonAnywhere上のあなたのウェブサイトは別のデータベースを使うことになるので、これをあなたのリポジトリには追加したくありません。 データベースは開発マシンのようにSQLiteにすることができますが、通常はSQLiteよりも多くのサイト訪問者に対処できるMySQLと呼ばれるものを使用します。 どちらの方法でも、GitHubのコードのコピーではSQLiteデータベースを無視することで、これまでに作成したすべての投稿はそのままローカルで利用できますが、本番環境（ブログを公開するPythonAnywhereのことです）ではそれらの投稿を再び追加する必要があります。 ローカルデータベースは本当のブログ投稿をブログから削除してしまうことを心配せずに、さまざまなことをテストできるよい遊び場として考えるといいでしょう。

//}


@<tt>{git add} コマンドを実行する前や、どのような変更を加えたか定かでない時は、 @<tt>{git status} コマンドを使用する事をおすすめします。 これは間違ったファイルを追加またはコミットなど思いもかけない事を止めるために役立ちます。 @<tt>{git status} コマンドは、あらゆる追跡されていない/変更されている/ステージされている（untracked/modifed/staged）ファイルや、ブランチの状態などさまざまな情報を返します。 出力は次のようになります。


//cmd{
$ git status
On branch master

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        .gitignore
        blog/
        manage.py
        mysite/
        requirements.txt

nothing added to commit but untracked files present (use "git add" to track)
//}


最後に、変更内容を保存します。コンソールに移動し、これらのコマンドを実行します。


//cmd{
$ git add --all .
$ git commit -m "My Django Girls app, first commit"
 [...]
 13 files changed, 200 insertions(+)
 create mode 100644 .gitignore
 [...]
 create mode 100644 mysite/wsgi.py
//}


=== GitHubにコードをプッシュする


@<href>{https://www.github.com, GitHub.com }にアクセスし、新しい無料のユーザーアカウントを登録します。 （もしあなたがすでにワークショップの準備でそれをしていたら、それは素晴らしいことです！）



そして、新しいリポジトリに "my-first-blog"の名前で新しいリポジトリを作成します。 "READMEで初期化する"チェックボックスをオフのままにし、.gitignoreオプションを空白にして（手動で行っています）、ライセンスをNoneのままにしておきます。



//image[new_github_repo][]{
//}



//quote{
@<strong>{注} @<tt>{my-first-blog}という名前は重要です。何か他のものを選択することもできますが、以下の手順では何度も繰り返す必要があります。他の名前を選択した場合は、 毎回それを置き換えてください。 できれば、@<tt>{my-first-blog} の名前にしておきましょう。

//}


次の画面では、リポジトリをクローンするためのURLが表示されます。これはこの後のコマンドで利用します。



//image[github_get_repo_url_screenshot][]{
//}




そして自分のコンピューター上のGitリポジトリをGitHub上のGitリポジトリに結びつけてあげる必要があります。



コンソールに次のように入力します（@<tt>{<your-github-username>}をGitHubアカウントの作成時に入力したユーザー名に置き換えます。山カッコ&lt;&gt;を残さないでください。このURLはさっき見たクローンURLと一致する必要があります）。


//cmd{
$ git remote add origin https://github.com/<your-github-username>/my-first-blog.git
$ git push -u origin master
//}


あなたのGitHubのユーザー名とパスワードを入力すると、次のように表示されます：


//cmd{
Username for 'https://github.com': ola
Password for 'https://ola@github.com':
Counting objects: 6, done.
Writing objects: 100% (6/6), 200 bytes | 0 bytes/s, done.
Total 3 (delta 0), reused 0 (delta 0)

To https://github.com/ola/my-first-blog.git
 * [new branch]      master -> master
Branch master set up to track remote branch master from origin.
//}


あなたのコードは今GitHub上にあります。 見に行きましょう！ @<href>{https://github.com/django/django, Django }や@<href>{https://github.com/DjangoGirls/tutorial, Django Girls Tutorial }、その他たくさんの素晴らしいオープンソースソフトウェアプロジェクトもGitHubでコードをホストしています。 :)


== PythonAnywhereでブログを設定する

=== PythonAnywhere アカウントにサインアップする

//quote{
@<strong>{備考：}あなたがすでにPythonAnywhereのアカウントを以前に作成しインストールの手順をふんでいたら、再びそれを行う必要はありません。

//}


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



=== PythonAnywhere でサイトを設定する


ロゴをクリックしてメインの@<href>{https://www.pythonanywhere.com/,PythonAnywhere Dashboard}に戻り、「Bash」コンソールを起動するボタンをクリックします。これはPythonAnywhereバージョンのコマンドラインで、ちょうどあなたのコンピューターのコマンドラインと同じようなものです。



//image[pythonanywhere_bash_console][]{
//}



//quote{
@<strong>{備考：}PythonAnywhere は Linuxベースなので、Windowsを使っている場合は、コンソールがあなたのものと少し違って見えるでしょう。

//}


PythonAnywhereにWebアプリケーションをデプロイするには、コードをGitHubからプルし、PythonAnywhereがそれを認識してWebアプリケーションのサーバを動かし始めるように設定する必要があります。 それを手動で行う方法もありますが、PythonAnywhereはそれをすべて行うヘルパーツールを提供しています。 まず、インストールしてみましょう。


//emlist[PythonAnywhere command-line]{
$ pip3.6 install --user pythonanywhere
//}


@<tt>{Collecting pythonanywhere} のようなメッセージがいくつか出力され、最終的に@<tt>{Successfully installed (...) pythonanywhere- (...)}という行で終わると思います。



GitHub からアプリを自動的に構成するためのヘルパーを実行します。 PythonAnywhereのコンソールに次のように入力します（GitHubからクローンしたときのURLと一致するように、@<tt>{<your-github-username>}の代わりにGitHubユーザー名を使用することを忘れないでください）：


//emlist[PythonAnywhere command-line]{
$ pa_autoconfigure_django.py https://github.com/<your-github-username>/my-first-blog.git
//}


実行しているところを見れば、何をしているのかわかるでしょう。

 * GitHubからコードをダウンロードする
 * PythonAnywhere上にvirtualenvを作成する。ちょうどあなたのPC上のように
 * 一部のデプロイメント設定で設定ファイルを更新する
 * @<tt>{manage.py migrate}コマンドを使ってPythonAnywhere上のデータベースをセットアップする
 * 静的ファイルの設定（これについては後で学習します）
 * APIを通じてPythonAnywhereがあなたのWebアプリケーションを提供するように設定する



PythonAnywhereではこれらすべてのステップは自動化されていますが、他のサーバープロバイダーでは同じ手順を経なければなりません。 今注目すべき重要な点は、PythonAnywhere上のデータベースが、自分のPC上のデータベースとはまったく別物であることです。つまり、異なる投稿と管理者アカウントを持つことができます。



その結果、自分のコンピュータで行ったように、@<tt>{createsuperuser}で管理者アカウントを初期化する必要があります。 PythonAnywhereがあなたのためにあなたのvirtualenvを自動的に起動したので、あなたがする必要があるのは以下の通りです：


//emlist[PythonAnywhere command-line]{
(ola.pythonanywhere.com) $ python manage.py createsuperuser
//}


管理者の詳細を入力します。 PythonAnywhere上のパスワードをより安全にしたい場合を除き、混乱を避けるために自分のコンピュータで使用しているのと同じものを使用することをお勧めします。



PythonAnywhereのコードを@<tt>{ls}を使って見てみることもできます：


//emlist[PythonAnywhere command-line]{
(ola.pythonanywhere.com) $ ls
blog db.sqlite3 manage.py mysite requirements.txt static
(ola.pythonanywhere.com) $ ls blog/
__init__.py __pycache__ admin.py forms.py migrations models.py static
templates tests.py urls.py views.py
//}


また、「ファイル」ページに移動し、PythonAnywhereに組み込まれているファイルブラウザを使用して閲覧することもできます。 (Consoleページから他のPythonAnywhereページには右上のメニューボタンからいけます。 一度いずれかのページに移動したら、他ページへのリンクはトップのあたりにあります。)


== 動いています！


あなたのサイトは現在、インターネット上で動作しているはずです！ PythonAnywhereの「Web」ページをクリックしてリンクを取得します。 あなたはあなたが望む誰とでもこれを共有することができます:)


//quote{
@<strong>{注} これは初心者向けのチュートリアルです。このサイトをデプロイする際にはセキュリティの観点からは理想的ではない、いくつかのショートカットをしました。 もしこのプロジェクトを利用すると決めたり、新しいプロジェクトを開始する場合は、あなたのサイトを保護するいくつかのヒントのために、@<href>{https://docs.djangoproject.com/ja/2.0/howto/deployment/checklist/,Djangoデプロイメントチェックリスト}を見直してみてください。

//}

== デバッギングのヒント


@<tt>{pa_autoconfigure_django.py}スクリプトの実行中にエラーが表示された場合は、次のような原因が考えられます。

 * PythonAnywhere APIトークンの作成を忘れている
 * あなたのGitHubのURLを間違えている
 * @<b>{Could not find your settings.py}というエラーが表示された場合は、おそらくGitにすべてのファイルを追加できていなかったか、 GitHubにうまくプッシュできていなかった。 この場合はGitセクションをもう一度見てください



サイトにアクセスしようとするとエラーが表示された場合、最初にデバッグ情報を探す場所は@<strong>{エラーログ}です。 PythonAnywhereの@<href>{https://www.pythonanywhere.com/web_app_setup/, Webページ}には、このリンクがあります。 そこにエラーメッセージがあるかどうかを確認してください。 最新のものは一番下にあります。



@<href>{http://help.pythonanywhere.com/pages/DebuggingImportError, PythonAnywhereヘルプサイトの一般的なデバッグのヒント}もあります。



つまづいた時は、コーチに助けを求めましょう。


== あなたのサイトをチェック！


サイトのデフォルトページでは、ローカルコンピュータと同じように「It worked！」と表示されます。 URLの最後に@<tt>{/admin/}を追加すると、管理サイトに移動します。 ユーザー名とパスワードでログインすると、新しい投稿をサーバーに追加することができます。



いくつかの投稿を作成したら、ローカル環境（PythonAnywhereではなく）に戻ることができます。 ここから、変更を加えるためにはあなたのローカル環境で作業する必要があります。 これがWeb開発の一般的なワークフローです。ローカルで変更し、それらの変更をGitHubにプッシュし、それからその変更を公開しているWebサーバーにプルしてきます。 これにより、公開しているWebサイトを壊すことなく作業したり試したりできます。 とってもクールでしょ？



自分を@<b>{すっごく}褒めてあげてください！ サーバーのデプロイはWeb開発の最も難しい部分の1つで、ちゃんと動くようになるまで数日かかることもよくあります。 しかし、あなたは実際のインターネット上で、あなたのサイトを動かす事ができました！
