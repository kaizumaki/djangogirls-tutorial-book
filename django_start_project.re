
= プロジェクトを作成しよう！

//quote{
このチャプターの一部はGeek Girls Carrotsのチュートリアルをもとにしています。(https://github.com/ggcarrots/django-carrots)



このチャプターの一部は Creative Commons Attribution-ShareAlike 4.0 International License のライセンスによる @<href>{http://django-marcador.keimlink.de/,django-marcador tutorial} をもとにしています。 この django-marcador tutorial は Markus Zapke-Gründemann たちが著作権を保有しています。

//}


ここからは、小さなブログを作っていきますよ！



最初のステップは、Djangoのプロジェクトを新しく作成します。 基本的に、Djangoのスクリプトを実行しDjangoプロジェクトの骨格を作ります。 スクリプトは、これから使う沢山のファイルやディレクトリを自動生成します。



Djangoでは、ファイルやディレクトリの名前がとても重要です。 作成されたファイルの名前は変えるべきではありません。 ファイルを移動させるのもいいアイディアとはいえません。 Djangoでは、重要なファイルを決められたファイル構成で作成しておくことが必要です。 


//quote{
virtualenv（仮想環境）を実行しているでしょうか。 もしコンソールのプロンプトの前に @<tt>{(myvenv)} という文字が表示されていない時は、virtualenv が実行されていないので、有効にする必要があります。 @<strong>{Djangoのインストール} のチャプターの @<strong>{仮想環境の操作} のパートで、仮想環境を実行する方法について説明しました。 Windowsでは、@<tt>{myvenv\Scripts\activate}、MacOS や Linux では、 @<tt>{source myvenv/bin/activate} というコマンドを入力すると有効にできます。

//}


====[column] Create project: OS X or Linux


MacOS や Linux の場合は、コンソールで以下のコマンドを実行します。最後のピリオド(ドット) @<tt>{.} を忘れないようにしてください！


//cmd[command-line]{
(myvenv) ~/djangogirls$ django-admin startproject mysite .
//}


//quote{
コマンドの最後にピリオド @<tt>{.} を入力したことを確認してくださいね。このピリオドは、現在の作業ディレクトリに Django をインストールするということを示しています (ピリオド @<tt>{.} は、現在のディレクトリを表す省略表記です)。



@<strong>{メモ:} 上記のコマンドを入力するときは、@<tt>{django-admin} で始まる部分のみを入力することを忘れないでください。 ここに書いた @<tt>{(myvenv) ~/djangogirls$} の部分は、コマンドライン上で入力を受け付けることを示しているプロンプトの一例なので、人によって違うかもしれません。
//}


====[/column]


====[column] Create project: Windows


Windows の場合は、以下のコマンドを実行しないといけません。(最後にピリオド (ドット) @<tt>{.\} を書いてください)


//cmd[command-line]{
(myvenv) C:\Users\Name\djangogirls> django-admin.exe startproject mysite .
//}


//quote{
コマンドの最後にピリオド (.) があることを確認してくださいね。これば、現在の作業ディレクトリにDjangoをインストールするということを示すので、とても重要なのです。(ピリオドは簡略表記です).



@<strong>{メモ:} 上記のコマンドを入力するときは、@<tt>{django-admin} で始まる部分のみを入力することを忘れないでください。 ここに書いた @<tt>{(myvenv) ~/djangogirls$} の部分は、コマンドライン上で入力を受け付けることを示しているプロンプトの一例なので、人によって違うかもしれません。
//}


====[/column]


django-admin.py は、必要なディレクトリとファイルを作成するスクリプトです。次のようなファイル構造が作成されましたね。:


//emlist{
djangogirls
├───manage.py
├───mysite
│        settings.py
│        urls.py
│        wsgi.py
│        __init__.py
└───requirements.txt
//}

//quote{
@<strong>{注}：ディレクトリ構造には、以前作成した@<tt>{venv}ディレクトリもあります。

//}


@<tt>{manage.py}はサイトの管理に役立つスクリプトです。 それを使用して、他のものをインストールすることなく、私たちのコンピュータ上でWebサーバーを起動することができます。



@<tt>{settings.py}ファイルには、ウェブサイトの設定が含まれています。



手紙を送付する場所を確認する郵便業者について話した事を覚えていますか？ @<tt>{urls.py}ファイルには、@<tt>{urlresolver}で使用されるパターンのリストが含まれています。



私たちが変更しない他のファイルを今は無視しましょう。 覚えておくべき唯一の事は、間違えてそれらを削除しないことです！


== 設定変更


@<tt>{mysite/settings.py}にいくつか変更を加えましょう。 前にインストールしたコードエディタを使用してファイルを開きます。



@<strong>{注}：@<tt>{settings.py}は他のものと同じように通常のファイルであることに注意してください。 「ファイルを開く」メニューを使用して、コードエディタ内から開くことができます。 これにより、@<tt>{settings.py}ファイルに移動して選択できる通常のウィンドウが表示されます。 あるいは、デスクトップのdjangogirlsフォルダに移動して右クリックしてファイルを開くこともできます。 次に、リストからコードエディタを選択します。 インストールされた他のプログラムでは、ファイルを開けても編集できないかもしれないので、エディタの選択は重要です。



私たちのWebサイトが正しい時間で動くといいでしょう。 @<href>{https://en.wikipedia.org/wiki/List_of_tz_database_time_zones,Wikipediaのタイムゾーンのリスト}に移動して、関連するタイムゾーン (TZ) をコピーします (例：@<tt>{Asia/Tokyo})。



@<tt>{settings.py} の中から @<tt>{TIME_ZONE} と書かれた行を探してください。この行はタイムゾーンを表しているので、自分が住んでいるタイムゾーンに合わせて修正しましょう。たとえば、次のように書きます。


//emlist[mysite/settings.py][python]{
TIME_ZONE = 'Asia/Tokyo'
//}


言語コードは、あなたの利用する言語を設定する必要があります。 英語の場合は@<tt>{en}、ドイツ語の場合は@<tt>{de}、国コードの場合は@<tt>{de}はドイツ、@<tt>{ch}はスイスです。 英語があなたの母国語でない場合、これを追加してDjangoのデフォルトのボタンや通知をあなたの言語に変更することができます。 ですのでたとえば「Cancel」ボタンがここで定義した言語に翻訳されます。 @<href>{https://docs.djangoproject.com/ja/2.0/ref/settings/#language-code,Djangoには多くの言語が付属しています}。



別の言語を使用する場合は、次の行を変更して言語コードを変更します。


//emlist[mysite/settings.py][python]{
LANGUAGE_CODE = 'ja'
//}


静的ファイルのパスも追加する必要があります。 （静的ファイルとCSSについては、後ほどチュートリアルで説明します）。ファイルの@<b>{一番下}に移動し、@<tt>{STATIC_URL}の下に @<tt>{STATIC_ROOT}を追加します。：


//emlist[mysite/settings.py][python]{
STATIC_URL = '/static/'
STATIC_ROOT = os.path.join(BASE_DIR, 'static')
//}


@<tt>{DEBUG} が @<tt>{True} に設定されていて、@<tt>{ALLOWED_HOSTS} が空のリストの時は、自動的に @<tt>{['localhost', '127.0.0.1', '[::1]']} という3つのホストに対してチェックが行われます。 このままの設定では、これから私たちがデプロイして使う PythonAnywhere のホストネームが含まれていません。ですから、次のように設定を変更します。


//emlist[mysite/settings.py][python]{
ALLOWED_HOSTS = ['127.0.0.1', '.pythonanywhere.com']
//}

//quote{
@<strong>{メモ}: Chromebook を使っている人は、次の1行を settings.py ファイルの最後に追加してください。


@<tt>{MESSAGE_STORAGE = 'django.contrib.messages.storage.session.SessionStorage'}



cloud9 のサービスを使っている人は、@<tt>{.c9users.io} も @<tt>{ALLOWED_HOSTS} に追加してください。

//}

== データベースをセットアップする


あなたのサイトのデータを保管することができるデータベース・ソフトウェアには、たくさんの種類があります。今は、Django がデフォルトで使う @<tt>{sqlite3} というデータベースを使うことにします。



この設定はすでに @<tt>{mysite/settings.py} ファイルの中に次のように書かれています。


//emlist[mysite/settings.py][python]{
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': os.path.join(BASE_DIR, 'db.sqlite3'),
    }
}
//}


ブログのデータベースを作成するには、コンソールで次のコードを実行してみましょう： @<tt>{python manage.py migrate} (@<tt>{manage.py}ファイルのある@<tt>{djangogirls}ディレクトリにいる必要があります) 。 うまくいったら次のように表示されるでしょう：


//cmd[command-line]{
(myvenv) ~/djangogirls$ python manage.py migrate
Operations to perform:
  Apply all migrations: auth, admin, contenttypes, sessions
Running migrations:
  Rendering model states... DONE
  Applying contenttypes.0001_initial... OK
  Applying auth.0001_initial... OK
  Applying admin.0001_initial... OK
  Applying admin.0002_logentry_remove_auto_add... OK
  Applying contenttypes.0002_remove_content_type_name... OK
  Applying auth.0002_alter_permission_name_max_length... OK
  Applying auth.0003_alter_user_email_max_length... OK
  Applying auth.0004_alter_user_username_opts... OK
  Applying auth.0005_alter_user_last_login_null... OK
  Applying auth.0006_require_contenttypes_0002... OK
  Applying auth.0007_alter_validators_add_error_messages... OK
  Applying sessions.0001_initial... OK
//}


終わったら、 Webサーバーを起動し、私たちのWebサイトが動作しているかどうかを確認する時間です。


== ウェブサーバを起動する


コマンドラインやコマンドプロンプトで@<tt>{manage.py}ファイルを含むディレクトリ（@<tt>{djangogirls}ディレクトリ）に移動してください。 @<tt>{python manage.py runserver}を実行してWebサーバーを起動できます。


//cmd[command-line]{
(myvenv) ~/djangogirls$ python manage.py runserver
//}


Chromebookを使用している場合は、代わりに次のコマンドを使用します。


//cmd[Cloud 9]{
(myvenv) ~/djangogirls$ python manage.py runserver 0.0.0.0:8080
//}


Windows上で、@<tt>{UnicodeDecodeError}で失敗した場合は、代わりに次のコマンドを使用します。


//cmd[command-line]{
(myvenv) ~/djangogirls$ python manage.py runserver 0:8000
//}


これであなたのウェブサイトが稼働していることを確認するだけです。 ブラウザ（Firefox、Chrome、Safari、Internet Explorerなど）を開き、次のアドレスを入力します。


//emlist[ブラウザ]{
http://127.0.0.1:8000/
//}


Chromebookを使用している場合は、次のURLからテストサーバーにアクセスします。


//emlist[ブラウザ]{
https://django-girls-<your cloud9 username>.c9users.io
//}


おめでとう！ たった今、あなたは最初のウェブサイトを作って、それをウェブサーバーの上で起動しました！ 素晴らしいですね！



//image[install_worked][インストールできました！]{
//}




Webサーバーが稼働している間は、追加のコマンドを入力するための新しいコマンドラインプロンプトは表示されません。 新しいテキストを受け入れますが、新しいコマンドは実行しません。 これは、Webサーバーが動作している間はずっとリクエストを待つためです。


//quote{
Webサーバーの仕組みについては、@<chapref>{how_the_internet_works}の章を参照してください。

//}


Webサーバーの実行中に追加のコマンドを入力するには、新しいターミナルウィンドウを開き、virtualenvをアクティブにします。 Webサーバーを停止するには、実行中のウィンドウに戻り、CTRL + C - ControlキーとCキーを同時に押します（WindowsではCtrl + Breakキーを押す必要があります）。



次のステップに進む準備はできましたか？ 今度は実際にコンテンツを作り始めましょう！
