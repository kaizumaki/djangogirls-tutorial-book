
= Djangoフォーム


私たちのWebサイトで最終的にやりたいことは、記事を追加したり編集したりするためのよい方法を作ることです。 @<tt>{Django admin}はかなりいいですが、カスタマイズしたりかわいくいい感じにするのはちょっと大変です。 @<tt>{フォーム} によってインターフェイスを完璧にコントロールできるようになります。想像するほとんど全てのことができます！



Djangoフォームのよいところは、フォームをゼロから定義できたり、フォームの結果をモデルに保存できる@<tt>{ModelForm}を作れたりするところです。



これはまさに私たちがやりたいことです：@<tt>{Post}モデルのためのフォームを作ります。



Djangoの他の重要なパーツと同様に、フォームは自身のファイルがあります: @<tt>{forms.py}



これは@<tt>{blog}ディレクトリの下にforms.pyの名前で作る必要があります。


//emlist{
blog
   └── forms.py
//}


このファイルをエディタで開き、次のコードを入力してください。


//emlist[blog/forms.py][python]{
from django import forms

from .models import Post

class PostForm(forms.ModelForm):

    class Meta:
        model = Post
        fields = ('title', 'text',)
//}


最初にDjangoのformsをインポート（@<tt>{from django import forms}）し、@<tt>{Post}モデルもインポート（@<tt>{from .models import Post}）する必要があります。



@<tt>{PostForm}とは何かと思うかもしれませんが、これはフォームの名前です。 このフォームが @<tt>{ModelForm} の一種だとDjangoに伝える必要があります (Djangoが私たちのためにいくつか魔法をかけられるように)。@<tt>{forms.ModelForm}がその役割を果たします。



次に@<tt>{class Meta}ですが、ここでDjangoにフォームを作るときにどのモデルを使えばいいか (@<tt>{model = Post}) を伝えます。



最後にフォームのフィールドに何を置くか書きます。 ここでは、私たちは@<tt>{title}（タイトル）と @<tt>{text}（本文）のみをフォームで使用します。 @<tt>{author} は現在ログインしている人（あなた）です。 @<tt>{created_date} は（コードによって）自動的に記事を書いた日時が設定されます。



ひとまずこれでおしまいです！あとはフォームを@<b>{ビュー}で使い、それをテンプレート内に表示しさえすればいいです。



もう一度、ページへのリンク、URL、ビューとテンプレートを作ります。


== フォームにおけるページへのリンク


@<tt>{blog/templates/blog/base.html}をエディタで開きましょう。@<tt>{page-header}と名付けた@<tt>{div}中に次のリンクを追加します：


//emlist[blog/templates/blog/base.html][html]{
<a href="{% url 'post_new' %}" class="top-menu"><span class="glyphicon glyphicon-plus"></span></a>
//}


新しいビュー@<tt>{post_new}を呼び出すことに注意してください。 @<tt>{"glyphicon glyphicon-plus"}クラスは、使用しているBootstrapテーマによって提供され、プラス記号を表示します。



行を追加すると、このような html ファイルになります。


//emlist[blog/templates/blog/base.html][html]{
{% load static %}
<html>
    <head>
        <title>Django Girls blog</title>
        <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
        <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">
        <link href='//fonts.googleapis.com/css?family=Lobster&subset=latin,latin-ext' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" href="{% static 'css/blog.css' %}">
    </head>
    <body>
        <div class="page-header">
            <a href="{% url 'post_new' %}" class="top-menu"><span class="glyphicon glyphicon-plus"></span></a>
            <h1><a href="/">Django Girls Blog</a></h1>
        </div>
        <div class="content container">
            <div class="row">
                <div class="col-md-8">
                    {% block content %}
                    {% endblock %}
                </div>
            </div>
        </div>
    </body>
</html>
//}


ファイルを保存して、ページ http://127.0.0.1:8000 をリロードすると見覚えのある @<tt>{NoReverseMatch} エラーが表示されると思います。実際にそうなってますか？いいですね！


== URL


@<tt>{blog/urls.py}をエディタで開き、次の内容を追加します。


//emlist[blog/urls.py][python]{
path('post/new', views.post_new, name='post_new'),
//}


すると最終的なコードは次のようになります:


//emlist[blog/urls.py][python]{
from django.urls import path 
from . import views

urlpatterns = [
    path('', views.post_list, name='post_list'),
    path('post/<int:pk>/', views.post_detail, name='post_detail'),
    path('post/new/', views.post_new, name='post_new'),
]
//}


サイトをリロードした後、@<tt>{AttributeError}が出ます。@<tt>{post_new}ビューの実装がないからです。ファイルに追加してみましょう。


== post_new ビュー


@<tt>{blog/views.py}をエディタで開き、@<tt>{from}の行の後に次の内容を追加してみましょう。


//emlist[blog/views.py][python]{
from .forms import PostForm
//}


その後に@<b>{ビュー}を追加します。


//emlist[blog/views.py][python]{
def post_new(request):
    form = PostForm()
    return render(request, 'blog/post_edit.html', {'form': form})
//}


@<tt>{Post}フォームを新しく作るには、@<tt>{PostForm()}を呼び出し、それをテンプレートに渡す必要があります。 あとでこの @<b>{ビュー} に戻ってきますが、今はフォームのためのテンプレートをすぐに作ってしまいましょう。


== テンプレート


@<tt>{blog/templates/blog}ディレクトリに@<tt>{post_edit.html}ファイルを作り、コードエディタで開きましょう。フォームを動かすにはいくつかやることがあります。

 * フォームを表示する必要があります。 私たちは（例えば）{% raw %}@<tt>{{{ form.as_p \}\}}{% endraw %} でこれを行うことができます。
 * 上記の行は HTMLのformタグでラップする必要があります：@<tt>{<form method="POST">...</form>}
 * @<tt>{Save} ボタンが必要です。これをHTMLのbuttonタグで行います：@<tt>{<button type="submit">Save</button>}
 * 最後に@<tt>{<form ...>} タグの開始直後に、 @<tt>{{% raw %\}{% csrf_token %\}{% endraw %\}}を追加する必要があります。 フォームをセキュアにするためこれは非常に重要です！ これを忘れると、Djangoはフォームを保存しようとすると文句を言うでしょう：



//image[csrf2][]{
//}




では、@<tt>{post_edit.html} のHTMLがどのようになるか見てみましょう:


//emlist[blog/templates/blog/post_edit.html][html]{
{% extends 'blog/base.html' %}

{% block content %}
    <h1>New post</h1>
    <form method="POST" class="post-form">{% csrf_token %}
        {{ form.as_p }}
        <button type="submit" class="save btn btn-default">Save</button>
    </form>
{% endblock %}
//}


更新をしてみましょう。やった！フォームが表示されます。



//image[new_form2][]{
//}




ちょっと待ってみて下さい。@<tt>{title} と @<tt>{text} フィールドに何か入力して保存するとどうなりますか？



何も起きません！もう一度同じページに戻りテキストはどこかに行ってしまいました… そして新しい投稿は追加されていません。何がいけなかったのでしょうか？



答えは: 何も間違ってない、です。@<b>{ビュー} でもう少し作業を行う必要があります.


== フォームを保存する


@<tt>{blog/views.py} をもう一度エディタで開きます。現在の @<tt>{post_new} ビューはこうなっています。


//emlist[blog/views.py][python]{
def post_new(request):
    form = PostForm()
    return render(request, 'blog/post_edit.html', {'form': form})
//}


フォームを送信したとき、同じビューに戻されていましたが、このとき@<tt>{request}、もっと詳しくいうと @<tt>{request.POST} にデータが追加されています (このPOSTという名前はブログ投稿 "post" とは関係ありません。このデータは送られてきたもの、というコトと関係しています) 。 HTMLファイルの @<tt>{<form>} タグで、@<tt>{method="POST"} という変数があったのを覚えていますか？ これによってフォームのすべてのフィールドは今 @<tt>{request.POST} にあります。 @<tt>{POST} という名前を何か別のものに変えることはできません (他に唯一の有効な @<tt>{method} の値は @<tt>{GET} ですが、その違いを説明する時間がありません) 。



私たちの @<b>{ビュー} では、扱わなくてはならない２つの別々のシチュエーションがあります: １つ目は、最初にページにアクセスしてきた時で空白のフォームが必要な場合。２つ目はすべてのフォームデータが入力された状態で@<b>{ビュー}に戻ってくる場合です。 したがって条件分岐を追加する必要があります（そのために@<tt>{if}を使います）：


//emlist[blog/views.py][python]{
if request.method == "POST":
    [...]
else:
    form = PostForm()
//}


ドット @<tt>{[...]} の部分を埋めていきましょう。 @<tt>{method}が@<tt>{POST}の場合、フォームのデータを使って@<tt>{PostForm}を構築します。 私たちはそれを次のようにします：


//emlist[blog/views.py][python]{
form = PostForm(request.POST)
//}


次にフォームの値が正しいかどうかをチェックします（すべての必須フィールドが設定され、不正な値が送信されないこと）。 @<tt>{form.is_valid()} で行います。



フォームをチェックして、フォームの値が有効であれば保存できます。


//emlist[blog/views.py][python]{
if form.is_valid():
    post = form.save(commit=False)
    post.author = request.user
    post.published_date = timezone.now()
    post.save()
//}


基本的にここでは2つのことを行います。まず @<tt>{form.save} でフォームを保存することと author を追加することです (@<tt>{PostForm} 内に @<tt>{author} フィールドがありませんし、このフィールドは必須です) 。 @<tt>{commit=False} は @<tt>{Post} モデルをまだ保存しないという意味です。保存前に author を追加したいので。 ほとんどの場合、@<tt>{commit = False}なしで@<tt>{form.save()}を使用しますが、この場合はそれを指定する必要があります。 @<tt>{post.save()}は変更を保存し（作成者を追加しつつ）、新しいブログ投稿が作成されます！



最後に、新しく作成された記事の @<tt>{post_detail} ページを表示できれば良いですよね? そのために次のインポートを追加します:


//emlist[blog/views.py][python]{
from django.shortcuts import redirect
//}


ファイルの先頭に追加します。これで新しく作成されたポストの @<tt>{post_detail} ページに移動する処理を書けます。


//emlist[blog/views.py][python]{
return redirect('post_detail', pk=post.pk)
//}


@<tt>{post_detail} は移動したいビューの名前です。 この @<b>{ビュー} では @<tt>{pk} 変数が必須であることを覚えていますか? ビューにそれを渡すため、@<tt>{pk=post.pk}を使います。この @<tt>{post} は新しく作られたブログポストです！



ふー、たくさんのことを話してきましたが、そろそろ @<b>{ビュー} の全体がどんな感じか見てみたい頃じゃないでしょうか？


//emlist[blog/views.py][python]{
def post_new(request):
    if request.method == "POST":
        form = PostForm(request.POST)
        if form.is_valid():
            post = form.save(commit=False)
            post.author = request.user
            post.published_date = timezone.now()
            post.save()
            return redirect('post_detail', pk=post.pk)
    else:
        form = PostForm()
    return render(request, 'blog/post_edit.html', {'form': form})
//}


では動作確認してみましょう。 http://127.0.0.1:8000/post/new/ に行き、 @<tt>{title} と @<tt>{text} を追加し、保存すると…… じゃじゃーん！ 新しいブログ記事が追加され、post_detail にリダイレクトされます！



ブログ記事を保存する前に公開日をセットしていることに気づいたかもしれません。後ほど、@<strong>{Django Girls Tutorial: Extensions}にて @<b>{公開ボタン} を導入します。



素晴らしい！


//quote{
最近までDjango adminを使ってきたので、システム上で今まだログイン状態かと思います。 いくつかの状況ではログアウト状態になることがあります(ブラウザを閉じる、DBを再起動するなど..)。 投稿を作成するときに、ログインユーザーがわからないというエラーが発生した場合は、管理ページhttp://127.0.0.1:8000/admin にアクセスして再度ログインしてください。 その問題は一時的に解決します。 メインチュートリアルの後 @<strong>{Homework: add security to your website!} の章に恒久的な対策がありますので宿題として取り組んでみてください。

//}


//image[post_create_error][]{
//}



== フォームのバリデーション(検証)


ここではDjangoのフォームのクールなところを紹介します。 ブログのポストは @<tt>{title} と @<tt>{text} のフィールドが必要です。 @<tt>{Post} モデルではこれらのフィールドがなくてもよいとは書いておらず (@<tt>{published_date} とは対照的に)、Djangoはその場合、それらのフィールドには何らかの値が設定されることを期待します。



@<tt>{title} と @<tt>{text} を入力せずに保存してみましょう。何が起こるでしょうか?



//image[form_validation2][]{
//}




Djangoはフォームのすべてのフィールドが正しいことを検証してくれます。気が利くでしょう?


== フォームの編集


今、私たちは新しいフォームを追加する方法を知っています。 しかし既存のデータを編集するためはどうすれば良いのでしょうか? それは先ほど行ったことと非常に似ています。 すぐにいくつかの重要なものを作成してみましょう。 （もしわからない場合、コーチに尋ねるか、もしくはすでに手順をカバーしているので、前の章を見てください）



@<tt>{blog/templates/blog/post_detail.html} をエディタで開いて次の行を追加します


//emlist[blog/templates/blog/post_detail.html][html]{
<a class="btn btn-default" href="{% url 'post_edit' pk=post.pk %}"><span class="glyphicon glyphicon-pencil"></span></a>
//}


テンプレートは次のようになります:


//emlist[blog/templates/blog/post_detail.html][html]{
{% extends 'blog/base.html' %}

{% block content %}
    <div class="post">
        {% if post.published_date %}
            <div class="date">
                {{ post.published_date }}
            </div>
        {% endif %}
        <a class="btn btn-default" href="{% url 'post_edit' pk=post.pk %}"><span class="glyphicon glyphicon-pencil"></span></a>
        <h1>{{ post.title }}</h1>
        <p>{{ post.text|linebreaksbr }}</p>
    </div>
{% endblock %}
//}


@<tt>{blog/urls.py}をエディタで開き、次の内容を追加します。


//emlist[blog/urls.py][python]{
    path('post/<int:pk>/edit/', views.post_edit, name='post_edit'),
//}


テンプレート @<tt>{blog/templates/blog/post_edit.html} を再利用します。そして残るは@<b>{ビュー}です。



@<tt>{blog/views.py} をエディタで開いて次の内容をファイルの最後に追加します：


//emlist[blog/views.py][python]{
def post_edit(request, pk):
    post = get_object_or_404(Post, pk=pk)
    if request.method == "POST":
        form = PostForm(request.POST, instance=post)
        if form.is_valid():
            post = form.save(commit=False)
            post.author = request.user
            post.published_date = timezone.now()
            post.save()
            return redirect('post_detail', pk=post.pk)
    else:
        form = PostForm(instance=post)
    return render(request, 'blog/post_edit.html', {'form': form})
//}


@<tt>{post_new} とほとんど同じに見えますか? しかし完全に同じではありません。 まずURLから追加の @<tt>{pk} パラメータを渡します。 次に編集したい@<tt>{Post} モデルを @<tt>{get_object_or_404(Post, pk=pk)} で取得し、フォームを作るときは以下の2つのケースのようにそのポストを@<tt>{instance（インスタンス）}として渡します。フォームを保存するときは…


//emlist[blog/views.py][python]{
form = PostForm(request.POST, instance=post)
//}


…このポストを編集するためにただフォームを開く場合は:


//emlist[blog/views.py][python]{
form = PostForm(instance=post)
//}


よし、ちゃんと動くか試してみましょう！@<tt>{post_detail} ページにいきましょう。そこの右上に [編集] ボタンがあるはずです：



//image[edit_button2][]{
//}




クリックするとブログ記事のフォームが表示されると思います：



//image[edit_form2][]{
//}




あとはお気軽にタイトルやテキストを変更して保存してください！



おめでとう！アプリケーションが完成しました。



Djangoのフォームについてもっと知りたい場合、Django Projectのドキュメントを読んでください: https://docs.djangoproject.com/ja/2.0/topics/forms/


== セキュリティ


リンクをクリックするだけで新しい投稿を作成できることは素晴らしいことです！ しかし、今、あなたのサイトにアクセスした人は誰でも新しいブログ投稿を作成することができます。それはおそらくあなたが望むものではありません。 ボタンはあなたのためには表示されますが、他の人には表示されないようにしましょう。



@<tt>{blog/templates/blog/base.html} をエディタで開き、@<tt>{page-header} と名付けた @<tt>{div} とそこに以前に入力したアンカータグを見つけます。 これは次のようになります。


//emlist[blog/templates/blog/base.html][html]{
<a href="{% url 'post_new' %}" class="top-menu"><span class="glyphicon glyphicon-plus"></span></a>
//}


これに@<tt>{{% if %\}}タグを追加し、管理者でログインしているユーザーのみにリンクを表示します。 今は、あなただけです！ @<tt>{<a>} タグを以下のように変更します：


//emlist[blog/templates/blog/base.html][html]{
{% if user.is_authenticated %}
    <a href="{% url 'post_new' %}" class="top-menu"><span class="glyphicon glyphicon-plus"></span></a>
{% endif %}
//}


この@<tt>{{% if %\}}は、ページをリクエストしているユーザーがログインしている場合にのみ、リンクがブラウザに送信されるようにします。 これは新しい投稿の作成を完全に保護するものではありませんが、それは良い第一歩です。 私たちは拡張レッスンでより多くのセキュリティをカバーします。



詳細ページに追加した編集アイコンを覚えていますか？ 他の人が既存の投稿を編集できないように、同じ変更を追加したいと思います。



@<tt>{blog/templates/blog/post_detail.html} をエディタで開いて次の行を見つけてください：


//emlist[blog/templates/blog/post_detail.html][html]{
<a class="btn btn-default" href="{% url 'post_edit' pk=post.pk %}"><span class="glyphicon glyphicon-pencil"></span></a>
//}


以下のように変更してください：


//emlist[blog/templates/blog/post_detail.html][html]{
{% if user.is_authenticated %}
     <a class="btn btn-default" href="{% url 'post_edit' pk=post.pk %}"><span class="glyphicon glyphicon-pencil"></span></a>
{% endif %}
//}


あなたはログインしている可能性が高いので、ページを更新しても、何も変わらないかもしれません。 ただし、別のブラウザやシークレットウィンドウ（Windows Edgeでは「InPrivate」と呼ばれます）でページを読み込むと、リンクが表示されず、アイコンも表示されないでしょう！


== もう一つ: デプロイの時間です!


ではPythonAnywhere上で動作するかを確認しましょう。再度デプロイします。

 * まず、Githubにあなたの新しく書いたコードをCommitして、Pushしてみましょう。


//cmd{
$ git status
$ git add --all .
$ git status
$ git commit -m "Added views to create/edit blog post inside the site."
$ git push
//}

 * それから、@<href>{https://www.pythonanywhere.com/consoles/,PythonAnywhereのbashコンソール}で：


//cmd{
$ cd ~/<your-pythonanywhere-username>.pythonanywhere.com
$ git pull
[...]
//}


(@<tt>{<your-pythonanywhere-username>}の部分を、自分の実際のPythonAnywhereのユーザー名に山カッコをはずして置き換えることを忘れずに)

 * 最後に、@<href>{https://www.pythonanywhere.com/web_app_setup/,「Web」ページ} に飛んで（コンソールの右上のメニューボタンを使って）それから @<strong>{Reload} を押しましょう。 変更を見るためにあなたのブログ https://yourname.pythonanywhere.com を再読み込みしましょう。



うまくいってるはずです！おめでとう :)
