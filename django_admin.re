
= Django admin


今作成したポストを追加、編集、削除するのにDjango adminを使います。



@<tt>{blog/admin.py}ファイルをエディタで開いて、内容をこのように変えて下さい：


//emlist[blog/admin.py][python]{
from django.contrib import admin
from .models import Post

admin.site.register(Post)
//}


見て分かる通り、前回定義したPostモデルをimportしています。 モデルをAdminページ（管理画面）上で見えるようにするため、@<tt>{admin.site.register(Post)}でモデルを登録する必要があります。



ではPostモデルを見てみましょう。 Web サーバーを実行するコンソールで @<tt>{python manage.py runserver} を実行してください。 ブラウザに行って http://127.0.0.1:8000/admin/ とアドレスバーにタイプします。 こんなログインページが出ますね。



//image[login_page2][]{
//}




ログインするには、@<i>{superuser}（サイトの全てを管理するユーザー）を作る必要があります。 コマンドラインに戻り、@<tt>{python manage.py createsuperuser} と入力し、enter キーを押します。


//quote{
Webサーバーを実行しているときに新しいコマンドを入力したい場合は、新しいターミナルウィンドウを開き、仮想環境（virtualenv）を有効にすることを思い出してください。 @<strong>{プロジェクトを作成しよう！}の@<strong>{ウェブサーバを起動する}セクションでどうやって新しいコマンドを書くかというのを見直しました。

//}


====[column] Mac OS X または Linux:


//cmd[command-line]{
(myvenv) ~/djangogirls$ python manage.py createsuperuser
//}


====[/column]


====[column] Windows:


//cmd[command-line]{
(myvenv) C:\Users\Name\djangogirls> python manage.py createsuperuser
//}


====[/column]


プロンプトが表示されたら、ユーザー名 (小文字、スペースなし)、電子メール アドレス、およびパスワードを入力します。 @<strong>{タイプしてる間パスワードは見えなくても大丈夫、それが正常です。}タイプして@<tt>{Enter}を押して続けましょう。 そうすればこのように見えるはずです。（ユーザーネームとパスワードは今あなたがタイプしたものです。）


//cmd[command-line]{
Username: admin
Email address: admin@admin.com
Password:
Password (again):
Superuser created successfully.
//}


ブラウザに戻ってsuperuserでログインすると、Django admin ダッシュボードが見えるでしょう。



//image[django_admin3][]{
//}




Postsに行って少し試してみてください。5～6のブログポストを入れてみましょう。コンテンツは心配しなくて大丈夫。今はとりあえずこのチュートリアルからテキストをいくつかコピペするだけでいいです。 （ブログ機能を確認するためなので、内容は何でも大丈夫です。自分で適当な文字列を打ち込んでももちろんOKです。）



少なくとも 2 つまたは 3 つの記事 (すべてではない) は公開日がセットされているようにしてください。後ほど役に立ちます。



//image[edit_post3][]{
//}




Django adminについてもっと知りたいときは、Djangoのドキュメントを見るとよいでしょう。 https://docs.djangoproject.com/ja/2.0/ref/contrib/admin/



ここでそろそろコーヒー（または紅茶）か何か食べるものを摂って自分を元気づけるのにいいタイミングでしょう。最初のDjangoモデルを作ったのだから、少し休みをとっていいところです！
