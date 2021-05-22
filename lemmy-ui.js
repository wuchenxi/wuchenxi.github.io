document.getElementByID("tweet").onclick=function(){window.open('https://twitter.com/intent/tweet?text=' + encodeURIComponent(document.title) + ':%20 ' + encodeURIComponent(document.URL));return false;};
document.getElementByID("fb-share").onclick=function(){window.open('https://www.facebook.com/sharer/sharer.php?u=' + encodeURIComponent(document.URL) + '&t=' + encodeURIComponent(document.URL)); return false;};
alert("hi");
