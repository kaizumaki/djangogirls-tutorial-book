
= テンプレートを拡張しよう


Djangoのまた別の素敵なところは@<strong>{テンプレート拡張}です。これは何を意味するのでしょうか？それはHTMLの共通部分をウェブサイトの異なるページで使えるということです。



テンプレートは同じ情報やレイアウトを複数の場所で利用したいときに役立ちます。 各ファイル内で繰り返す必要はありません。 さらにもし何か変更したい場合、各テンプレートを変更する必要はなく、1回変更すればいいだけです！


== 基本テンプレートを作成する


基本テンプレートはあなたのウェブサイトの各ページを拡張するための最も基本的なテンプレートです。



@<tt>{blog/templates/blog/}以下に@<tt>{base.html}ファイルを作ってみましょう。


//emlist{
blog
└───templates
    └───blog
            base.html
            post_list.html
//}


それからコードエディタで開いて、以下のように@<tt>{post_list.html}から@<tt>{base.html}ファイルにすべてコピーしましょう。



{% filename %}blog/templates/blog/base.html{% endfilename %}


//emlist[][html]{
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
            <h1><a href="/">Django Girls Blog</a></h1>
        </div>

        <div class="content container">
            <div class="row">
                <div class="col-md-8">
                {% for post in posts %}
                    <div class="post">
                        <div class="date">
                            {{ post.published_date }}
                        </div>
                        <h1><a href="">{{ post.title }}</a></h1>
                        <p>{{ post.text|linebreaksbr }}</p>
                    </div>
                {% endfor %}
                </div>
            </div>
        </div>
    </body>
</html>
//}


それから@<tt>{base.html}内の@<tt>{<body>}全体(@<tt>{<body>}と@<tt>{</body>}の間のすべて)を次で置き換えます。



{% filename %}blog/templates/blog/base.html{% endfilename %}


//emlist[][html]{
<body>
    <div class="page-header">
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
//}


{% raw %}@<tt>{{% for post in posts %\}} から @<tt>{{% endfor %\}} が以下のように置き換えられたことに気づいたでしょうか。 {% endraw %}



{% filename %}blog/templates/blog/base.html{% endfilename %}


//emlist[][html]{
{% block content %}
{% endblock %}
//}


でも何のために？ あなたはただ@<tt>{block}を作っただけです！ @<tt>{{% block %\}} テンプレートタグを、これからHTMLを挿入しようとする場所に使いました。 そのHTMLはこのテンプレート (@<tt>{base.html}) を拡張した別のテンプレートからやってきます。 どうやって行うかはすぐに示します。



@<tt>{base.html}を保存し、もう一度@<tt>{blog/templates/blog/post_list.html}をコードエディタで開きます。 {% raw %} @<tt>{{% for post in posts %\}} の上と @<tt>{{% endfor %\}} の下すべてを削除しましょう。 それが終わったら以下のようになっていると思います。{% endraw %}



{% filename %}blog/templates/blog/post_list.html{% endfilename %}


//emlist[][html]{
{% for post in posts %}
    <div class="post">
        <div class="date">
            {{ post.published_date }}
        </div>
        <h1><a href="">{{ post.title }}</a></h1>
        <p>{{ post.text|linebreaksbr }}</p>
    </div>
{% endfor %}
//}


これをcontentブロックに対応するテンプレートのパーツとして使いたいです。このファイルにblockタグを追加する時です！



{% raw %}追加するblockタグは @<tt>{base.html} ファイル中のタグにマッチしてほしいですよね。 また、blockタグにはcontentブロックに属するすべてのコードを含めたいですよね。 そうするには、すべてを @<tt>{{% block content %\}} と @<tt>{{% endblock %\}} の間に入れてあげればよいです。 このように:{% endraw %}



{% filename %}blog/templates/blog/post_list.html{% endfilename %}


//emlist[][html]{
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


あとやることは一つだけです。これら二つのテンプレートをくっつけてあげる必要があります。これがテンプレートを拡張するということのすべてです！そうするにはこのファイルの先頭にextendsタグを追加します。次のように：



{% filename %}blog/templates/blog/post_list.html{% endfilename %}


//emlist[][html]{
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


以上です！ファイルを保存して、ウェブサイトがまだちゃんと動いているか確認しましょう。:)


//quote{
もし @<tt>{TemplateDoesNotExist} というエラーが出ていたら、 @<tt>{blog/base.html} ファイルがないという意味で、コンソールで @<tt>{runserver} が実行されたままになっていると思います。 これを止め(Ctrl+C - ControlとCのキーを同時押し)、それから @<tt>{python manage.py runserver}コマンドを入力して再度サーバーを動かしてみてください。

//}
