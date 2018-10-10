
= アプリケーションを拡張しよう


もう、ウェブサイトを作るのに必要な全ての章は終わりました。どのようにモデル、URL、ビュー、テンプレートを書いたら良いかわかっていますし、またウェブサイトを素敵にするやり方もわかります。



さあ練習しましょう！



ブログに最初に必要なものはおそらく、記事を表示するページですよね。



もう@<tt>{Post}モデルが入っていますから、@<tt>{models.py}は追加する必要はありません


== 投稿の詳細へのテンプレートリンクを作成する


@<tt>{blog/templates/blog/post_list.html}ファイルにリンクを追加していきましょう。 コードエディタで開いたら、次のようになっていますよね：


//emlist[blog/templates/blog/post_list.html][html]{
{% extends 'blog/base.html' %}

{% block content %}
    {% for post in posts %}
        <div class="post">
            <div class="date">
                {{ post.published_date }}
            </div>
            <h1><a href="">{{ post.title }}</a></h1>
            <p>{{ post.text|linebreaksbr }}</p>
        </div>
    {% endfor %}
{% endblock %}
//}


投稿リストの投稿のタイトルから投稿の詳細ページへのリンクを作りたいです。 投稿の詳細ページにリンクするように@<tt>{<h1><a href="">{{ post.title \}\}</a></h1>}を変更しましょう。


//emlist[blog/templates/blog/post_list.html][html]{
@<seqsplit>{<h1><a href="{% url 'post_detail' pk=post.pk %\}">{{ post.title }}</a></h1>}
//}


不思議な@<tt>{{％ url 'post_detail' pk = post.pk ％\}}を説明します。 気づいたかもしれませんが、@<tt>{{% %\}}という表記はDjangoのテンプレートタグを使用していることを意味しています。 今私たちはこれをURLを作るために使います！



@<tt>{post_detail}の部分は、Djangoが@<tt>{blog/urls.py}に書かれた name=post_detail のURLを待ち受けることを表しています。



そして@<tt>{pk=post.pk}についてはどうでしょうか？ @<tt>{pk}はプライマリキーの略で、データベースの各レコードのユニークな名前です。 @<tt>{Post}モデルでプライマリキーを指定しなかったので、Djangoは私たちのために1つのキーを作成し（デフォルトでは、各レコードごとに1ずつ増える数字で、たとえば1、2、3です）、各投稿に@<tt>{pk}というフィールド名で追加します。 @<tt>{Post}オブジェクトの他のフィールド（@<tt>{title}、@<tt>{author}など）にアクセスするのと同じ方法で、@<tt>{post.pk}と書くことによってプライマリキーにアクセスします！



さて、私たちが http://127.0.0.1:8000/ に行くとエラーが出ます（知っての通り、URLも@<tt>{post_detail}の@<b>{ビュー}もまだ作っていないので）。 このようになります：



//image[no_reverse_match2][]{
//}



== 投稿の詳細へのURLを作成する


@<tt>{post_detail} @<b>{ビュー}用に@<tt>{urls.py}にURLを作成しましょう！



最初の投稿の詳細がこの@<strong>{URL}で表示されるようにします：http://127.0.0.1:8000/post/1/



投稿の内容を表示する@<tt>{post_detail}という@<b>{ビュー}をDjangoに示すように、@<tt>{blog/urls.py}ファイルでURLを作りましょう。 @<tt>{blog/urls.py}をコードエディタで開いて、@<tt>{path('post/<int:pk>)/', views.post_detail, name='post_detail'),}という行を追加しましょう。ファイルは次のようになるでしょう。


//emlist[blog/urls.py][python]{
from django.urls import path
from . import views

urlpatterns = [
    path('', views.post_list, name='post_list'),
    path('post/<int:pk>/', views.post_detail, name='post_detail'),
]
//}


@<tt>{post/<int:pk>/} の部分はURLパターンを指定しています。それについて説明しましょう:

 * @<tt>{post/} はURLが @<strong>{post} に続けて @<strong>{/} で始まることを意味します。ここまでは順調ですね。
 * @<tt>{<int:pk>} – この部分はトリッキーです。これはDjangoは整数の値を期待し、その値が@<tt>{pk}という名前の変数でビューに渡されることを意味しています。
 * @<tt>{/} – それからURLの最後に再び @<strong>{/} が必要です。



つまり、ブラウザに@<tt>{http://127.0.0.1:8000/post/5/}を入力すると、Djangoは@<tt>{post_detail}という@<b>{ビュー}を探していると理解します。そして@<tt>{pk}が@<tt>{5}という情報をその@<b>{ビュー}に転送します。



よし、私たちは @<tt>{blog/urls.py} に新しい URL パターンを追加しました！ ページを更新しましょう：http://127.0.0.1:8000/ ドーン！ サーバーが再び実行を停止しました。 コンソールを見てください - 予想通り、もう一つのエラーがあります！



//image[attribute_error2][]{
//}




あなたは次のステップが何であるか覚えていますか？ ビューを追加する！ですね。


== 投稿の詳細ビューを追加する


今回は@<b>{ビュー}に追加のパラメータ@<tt>{pk}が与えられます。 私たちの@<b>{ビュー}はそれを受け取る必要がありますね？ そこで関数を@<tt>{def post_detail(request, pk):}として定義します。 urlsで指定した名前（@<tt>{pk}）とまったく同じ名前を使用する必要があることに注意してください。 この変数を省略するのは正しくないのでエラーになってしまいます！



今、私たちは1つだけブログ投稿を取得したいと考えています。 これを行うには、次のようなクエリセットが使用できます。


//emlist[blog/views.py][python]{
Post.objects.get(pk=pk)
//}


しかし、このコードには問題があります。 与えられた@<tt>{プライマリキー}（@<tt>{pk}）を持つ@<tt>{Post}が存在しない場合、とてもダサいエラーが発生します。



//image[does_not_exist2][]{
//}




私たちはそれを望んでいません！ しかし幸運にもDjangoにはそれを処理するものがあります：@<tt>{get_object_or_404} です。 与えられた@<tt>{pk}の@<tt>{Post}がない場合、前よりもっとよい @<tt>{Page Not Found 404} ページが表示されます。



//image[404_2][]{
//}




いい知らせとして実際には自分の@<tt>{Page not found}ページを作って自分の好きなようにきれいにすることができます。しかしそれは今すごく重要ではないので、私たちはそれをスキップします。



よし、今こそ@<b>{ビュー}を@<tt>{views.py}ファイルに追加するときです！



@<tt>{blog/urls.py}では@<tt>{views.post_detail}というビューを参照する@<tt>{post_detail}という名前のURLルールを作成しました。 これは、Djangoが@<tt>{blog/views.py}内の@<tt>{post_detail}というビュー関数を待っていることを意味します。



@<tt>{blog/views.py}をコードエディタで開き、他の@<tt>{from}行の近くに次のコードを追加する必要があります。


//emlist[blog/views.py][python]{
from django.shortcuts import render, get_object_or_404
//}


ファイルの最後に@<b>{ビュー}を追加します：


//emlist[blog/views.py][python]{
def post_detail(request, pk):
    post = get_object_or_404(Post, pk=pk)
    return render(request, 'blog/post_detail.html', {'post': post})
//}


ページを更新してみましょう：http://127.0.0.1:8000/



//image[post_list2][]{
//}




出来ましたね！ しかし、ブログ投稿のタイトルのリンクをクリックするとどうなりますか？



//image[template_does_not_exist2][]{
//}




あらいやだ！ 別のエラー！ しかし、私たちはすでにそれに対処する方法をすでに知っていますね。 そう！テンプレートを追加する必要があります！


== 投稿の詳細へのテンプレートリンクを作成する


@<tt>{blog/templates/blog}に@<tt>{post_detail.html}というファイルを作成し、コードエディタで開きます。



こんな感じですね。



//emlist[blog/templates/blog/post_detail.html][html]{
{% extends 'blog/base.html' %}

{% block content %}
    <div class="post">
        {% if post.published_date %}
            <div class="date">
                {{ post.published_date }}
            </div>
        {% endif %}
        <h1>{{ post.title }}</h1>
        <p>{{ post.text|linebreaksbr }}</p>
    </div>
{% endblock %}
//}


もう一度@<tt>{base.html}を拡張します。 @<tt>{content}ブロックでは、投稿の公開日（存在する場合）、タイトル、およびテキストを表示します。 ここで重要なポイントについて見てみます。



@<tt>{{% if ... %\} ...  {％endif％\}}は、何かをチェックしたいときに使用できるテンプレートタグです。 (@<tt>{if ... else...} を@<strong>{Python入門}のチャプターでやったのを覚えていますか？) この場合、私たちは投稿の@<tt>{公開日（published_date）}が空でないかを確認したいです。



これで、ページを更新して@<tt>{TemplateDoesNotExist}がもうなくなったかどうか確認できます。



//image[post_detail2][]{
//}




イェーイ！うまくできていますね！


== デプロイの時間です！


あなたのウェブサイトがまだPythonAnywhere上で動くとしたらいいでしょう？またデプロイしてみましょう。


//cmd[command-line]{
$ git status
$ git add --all .
$ git status
@<seqsplit>{$ git commit -m "Added view and template for detailed blog post as well as CSS for the site."}
$ git push
//}


それから、@<href>{https://www.pythonanywhere.com/consoles/,PythonAnywhere Bash コンソール}で：


//cmd[PythonAnywhere command-line]{
$ cd ~/<your-pythonanywhere-username>.pythonanywhere.com
$ git pull
[...]
//}


(@<tt>{<your-pythonanywhere-username>}の部分を、自分の実際のPythonAnywhereのユーザー名に山カッコをはずして置き換えることを忘れずに)


== サーバー上の静的ファイルの更新


PythonAnywhereのようなサーバは、（CSSファイルのような）「静的ファイル」をPythonファイルとは違って扱うのが好きです。なぜなら、それらが高速に読み込まれるように最適化できるからです。 その結果、CSSファイルを変更するたびに、サーバー上で追加のコマンドを実行して、更新するように指示する必要があります。 コマンドは@<tt>{collectstatic}です。



もし仮想環境（virtualenv）が有効になっていなければ有効化するところから始めましょう (PythonAnywhereではこれを行うために@<tt>{workon}というコマンドを使用します。これはあなたが自身のコンピュータで使用している@<tt>{source myenv/bin/activate}コマンドと同じようなものです) 。


//cmd[PythonAnywhere command-line]{
$ workon <your-pythonanywhere-username>.pythonanywhere.com
(ola.pythonanywhere.com)$ python manage.py collectstatic
[...]
//}


@<tt>{manage.py collectstatic}コマンドは、@<tt>{manage.py migrate}のようなものです。 私たちはコードをいくつか変更してから、Djangoにサーバの静的ファイルのコレクションまたはデータベースに変更を@<b>{適用}するよう指示します。



いずれにしても、@<href>{https://www.pythonanywhere.com/web_app_setup/,「Web」ページ}（コンソールの右上のメニューボタンから）を開き、@<strong>{Reload}をクリックする準備ができました。そしてそれから https://yourname.pythonanywhere.comページを見て結果を確認しましょう。



うまくいってるはずです！おめでとう :)
