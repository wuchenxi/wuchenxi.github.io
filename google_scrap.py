from GoogleNews import GoogleNews
import sys
googlenews=GoogleNews(lang='en', period='7d', encode='utf-8')
googlenews.search("Asian American")
for i in range(2, 11):
    googlenews.get_page(i)
r=googlenews.results(sort=True)
print(len(r))

fn=sys.argv[1]
output=open(fn, "w")
print("<!DOCTYPE html>\n<html>\n<body>\n", file=output)
for item in r:
    print("<p>"+item['date']+" <a href=\""+item['link']+"\">"+item['title']+"</a> "+item['media']+"</p>", file=output)
    print("<p>"+item['desc']+"</p>", file=output)
print("</body>\n</html>", file=output)
output.close()

