
= Djangoビュー – 今こそ作りましょう！


それでは前の章の続きをやりましょう。確かビューの作成がまだだったので、エラーになっていましたね！:)



@<b>{ビュー} はアプリのロジックを書いていくところです。 ビューは、以前あなたが作った @<tt>{モデル} に情報を要求し、それを @<tt>{テンプレート} に渡します。 テンプレートは、次の章で作ります。 ビューはただのPythonの関数です。@<strong>{Python入門}の章で書いたものよりもちょっと複雑なだけですよ。



ビューは、@<tt>{views.py} に記述します。私たちの場合 @<tt>{blog/views.py} に書くことになります。


== blog/views.py


では、早速 blog/views.py をコードエディタで開いてみましょう：


//emlist[blog/views.py][python]{
from django.shortcuts import render

# Create your views here.
//}


まだ何もないですね。



@<tt>{#} で始まる行は、コメントです。この行に書いたものはPythonは無視します。



それでは、次のようなちょっとした @<b>{ビュー} を作ってみましょう。


//emlist[blog/views.py][python]{
def post_list(request):
    return render(request, 'blog/post_list.html', {})
//}


みてのとおり、@<tt>{post_list} という関数 (@<tt>{def} から始まる部分のことです) を作りました。これは @<tt>{request} を引数に取り、@<tt>{blog/post_list.html}テンプレートを表示する (組み立てる) @<tt>{render} 関数を @<tt>{return} しています。



ファイルを保存したら、どんな風に表示されるか、ブラウザで http://127.0.0.1:8000/ を確認してみましょう。



今度は別のエラーになりましたね。なんと書いてあるでしょうか。



//image[error][]{
//}




サーバーは実行されていることはわかるのですが、正しく表示されないのはなぜでしょう？ 心配しないで！ただのエラーページです！ コンソールでのエラーメッセージと同じように、これは実際にかなり便利です。 @<b>{TemplateDoesNotExist} と書いてありますね。 それでは次の章でテンプレートを作って、エラーを解決しましょう！


//quote{
Djangoのビューについてもっと知りたいのなら、オフィシャルドキュメントを是非読んでみてください。 https://docs.djangoproject.com/ja/2.0/topics/http/views/

//}
