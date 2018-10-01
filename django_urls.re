
= Django URL


もうすぐ最初のWebページ、あなたのブログのホームページを作るところです！でも最初に、ちょっとだけDjangoのURLについて学びましょう。


== URLとは？


URLはWeb上のアドレスです。 サイトのURLは、ブラウザのアドレスバーで見ることができます。 （そう、 @<tt>{127.0.0.1:8000} や @<tt>{http://djangogirls.com} がURLです。）



//image[url][URL]{
//}




インターネット上のすべてのページには、独自のURLが必要です。 それによって、これから作るアプリケーションが、URLを指定してアクセスしてきたユーザに、何を見せたらいいのかわかるのです。 Djangoでは @<tt>{URLconf}（URL設定）と呼ばれるものを使います。 URLconfはパターンの集まりで、適切なビューを見つけるために、DjangoがリクエストされたURLと照合するものです。


== DjangoでURLはどのように機能する？


@<tt>{mysite/urls.py} を開いて、中身をみてみると：



{% filename %}mysite/urls.py{% endfilename %}


//emlist[][python]{
"""mysite URL Configuration

[...]
"""
from django.urls import path, include
from django.contrib import admin

urlpatterns = [
    path('admin/', admin.site.urls),
]
//}


ご覧のとおり、Djangoは既にこのようなものを置いてくれています。



三重クオート（ @<tt>{'''} や @<tt>{"""} ）で囲まれた行は、docstringとよばれるコメント行です。ファイル、クラス、またはメソッドの先頭に記述して、それが何をするかを説明するのに用います。 これはPythonによって実行されない行です。



前の章で訪れたadminのURLについてはすでに書いてありますね。



{% filename %}mysite/urls.py{% endfilename %}


//emlist[][python]{
    path('admin/', admin.site.urls),
//}


@<tt>{admin/} で始まる全てのURLについて、Djangoが返すべき@<b>{ビュー}をこの行で指定しています。 今回の場合、adminで始まるURLをたくさん作ることになりますが、その全てをこの小さいファイルに書くようなことはしません。この方がきれいで読みやすいですし。


== あなたの初めてDjango URL!


さあ最初のURLを作りましょう！'http://127.0.0.1:8000/' をブログの入口ページにして、投稿したブログポストのリストを表示するようにしたいと思います。



@<tt>{mysite/urls.py} ファイルは簡潔なままにしておきたいので、@<tt>{mysite/urls.py} では@<tt>{blog} アプリからURLをインポートするだけにしましょう。



まず、@<tt>{blog.urls} をインポートする行を追加しましょう。 また、ここで@<tt>{include}関数を使うので、最初の行を変更し、そのインポートも追加する必要があります。



@<tt>{mysite/urls.py} ファイルはこのようになります：



{% filename %}mysite/urls.py{% endfilename %}


//emlist[][python]{
from django.urls import path, include
from django.contrib import admin

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('blog.urls')),
]
//}


これでDjangoは'http://127.0.0.1:8000/' に来たリクエストは @<tt>{blog.urls} へリダイレクトするようになり、それ以降はそちらを参照するようになります。


== blogのURL


@<tt>{blog} ディレクトリの下に、新しく @<tt>{urls.py} という空のファイルを作って、コードエディタで開いて下さい。そして最初の2行を以下のように書きます：



{% filename %}blog/urls.py{% endfilename %}


//emlist[][python]{
from django.urls import path
from . import views
//}


これはDjangoの @<tt>{path} 関数と、@<tt>{blog} アプリの全ての @<tt>{ビュー}（といっても、今は一つもありません。すぐに作りますけど！）をインポートするという意味です。



その後、最初のURLパターンを追加します。



{% filename %}blog/urls.py{% endfilename %}


//emlist[][python]{
urlpatterns = [
    path('', views.post_list, name='post_list'),
]
//}


見てのとおり、@<tt>{post_list} という名前の @<tt>{ビュー} をルートURLに割り当てています。 このURLパターンは空の文字列に一致し、Djangoはビューを見つけるとき、URLのフルパスの前半にくっつくドメイン名（つまり、http://127.0.0.1:8000/ の部分）を無視します。 このパターンは誰かがあなたのWebサイトの 'http://127.0.0.1:8000/' というアドレスにアクセスしてきたら @<tt>{views.post_list} が正しい行き先だということをDjangoに伝えます。



最後の @<tt>{name='post_list'} は、ビューを識別するために使われるURL の名前です。 これはビューと同じ名前にすることもできますが、全然別の名前にすることもできます。 プロジェクトでは名前づけされたURLを後で使うことになるので、アプリのそれぞれのURLに名前をつけておくのは重要です。また、URLの名前はユニークで覚えやすいものにしておきましょう。



もし今 http://127.0.0.1:8000/ にアクセスしたら、'web page not available' のようなメッセージが出るでしょう。 これはサーバー（ @<tt>{runserver} ってタイプしたのを覚えていますか？）が動いていないからです。 なぜこうなったのかを知るためにサーバーのコンソール画面を見てみましょう。



//image[error1][エラー]{
//}




エラーが表示されていますね。でも心配しないで。これはむしろ、結構便利なものなんですよ：ここでは、@<strong>{'post_list' という属性(attribute)がない}ことを知らせてくれています。 これは @<b>{ビュー} の名前で、Djangoが探して使おうとしましたが、私たちはこれをまだ作っていませんでした。 現時点では、@<tt>{/admin/} も動作していないと思います。 心配しなくて大丈夫です。ちゃんとできますから。 別のエラーメッセージが表示された場合は、Webサーバーを再起動してみてください。 Webサーバーが動いているコンソール画面で、Ctrl+C（ControlとCのキーを同時に）を押してサーバーを止め、@<tt>{python manage.py runserver}コマンドを実行して再起動します。


//quote{
Django URLconfについてもっと知りたい場合は、公式のドキュメントを見て下さい： https://docs.djangoproject.com/ja/2.0/topics/http/urls/

//}
