class TagCloud:
    def __init__(self, pairs):
        '''pairs is a list consisting of pairs of (word, frequency), like
        -------[('hi',5),('there',6),('mom',10)]'''
        self.pairs = pairs

    def outputHTML(self, name):
        pairs = sorted(self.pairs, key = lambda d: d[1], reverse = True)
        if len(pairs) > 40: pairs = pairs[:40]

        high_count = pairs[0][1]
        low_count = pairs[-1][1]

        pairs = sorted(pairs)

        body = ''
        for word, cnt in pairs:
            body = body + self._makeHTMLword(word, cnt, high_count, low_count)
        box = self._makeHTMLbox(body)
        self._printHTMLfile(box, name)

    def _printHTMLfile(self, body, title):
        ''' create a standard html page with titles, header etc.
        and add the body (an html box) to that page. File created is title+'.html'
        '''
        fd = open(title+'.html','w')
        theStr="""
        <!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML//EN">
        <html> <head>
        <title>"""+title+"""</title>
        </head>

        <body>
        <h1>"""+title+'</h1>'+'\n'+body+'\n'+"""<hr>
        <address></address>
        <!-- hhmts start --> Last modified: Fri Oct 10 10:09:41 EDT 2008 <!-- hhmts end -->
        </body> </html>
        """
        fd.write(theStr)
        fd.close()

    def _makeHTMLbox(self, body):
        ''' make and HTML box that has all the words in it
        '''
        boxStr = """<div style=\"
        width: 800px;
        background-color: rgb(250,250,250);
        border: 1px grey solid;
        text-align: center\">%s</div>
        """
        return boxStr % (body)

    def _makeHTMLword(self, word,cnt,high,low):
        ''' make a word with a font size to be placed in the box. Font size is scaled
        between htmlBig and htmlLittle (to be user set). high and low represent the high 
        and low counts in the document. cnt is the cnt of the word 
        '''
        htmlBig = 96
        htmlLittle = 14
        ratio = (cnt-low)/float(high-low)
        fontsize = htmlBig*ratio + (1-ratio)*htmlLittle
        fontsize = int(fontsize)
        wordStr = '<span style=\"font-size:%spx;\">%s</span> '
        return wordStr % (str(fontsize), word)

# example usage
if __name__ == '__main__':
    pairs = [('hi',5),('there',6),('mom',10),('fred',2),('bill',20)]
    tg = TagCloud(pairs)
    tg.outputHTML('testFile') #testFile.html is generated
