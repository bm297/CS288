import libxml2    # DOM Libaray
import sys
import os         #module provides a portable way of using operating system dependent functionality
import commands
import re
import sys
import MySQLdb

from xml.dom.minidom import parse, parseString

#for converting dict to xml 
from cStringIO import StringIO
from xml.parsers import expat

def extract_values(dm):
   l = get_elms_for_atr_val('tr','class','most_actives')
   lst = map(lambda e: get_text(e), l)
   
   # Remove table header from lst
   lst = lst[1:]

   # Delete the /n items in lst
   for x in lst: # x is each element in the lst
      index = 0 # Mark the null item in x
      for y in x: # y is each item in x
         if(y == '\n'): # Check if the item is null
            del x[index] # Delete the null item from x
         index += 1 # Increment index for next iteme in x
   
   dict = map(lambda x: tr_to_dict(x), lst)
   return dict

def get_elms_for_atr_val(tag,atr,val):
   lst=[]
   elms = dom.getElementsByTagName(tag)
   lst = filter(lambda t: len(t.childNodes) == 6, elms)
   return lst

# get all text recursively to the bottom
def get_text(e):
   lst=[]
   if e.nodeType in (3,4):
      lst.append(e.nodeValue)
   else:
      for x in e.childNodes:
         lst = lst + get_text(x)
   return lst

def tr_to_dict(x):
   d = {}
   lst = x[1].split(' (')
   d['name'] = lst[0]
   d['symbol'] = lst[1].replace(')\n', '')
   d['volume'] = x[2].replace(',','')
   d['price'] = x[3].replace('$', '') # First tr has $, breaks mysql syntax
   d['chng'] = x[4]
   d['pchange'] = x[5]
   return d
  
# convert to xhtml
# use: java -jar tagsoup-1.2.jar --files html_file
def html_to_xml(fn):
   # Local java -jar tagsoup file
   html_to_xhtml = "java -jar tagsoup-1.2.jar --files " + fn
   # Execute command (a String) in subshell
   os.system(html_to_xhtml)
   # The xhtml webpage has been tagsouped but has no reference
   # Update the return file(reference) from .html to .xhtml extension
   xhtml_file = fn.replace(".html",".xhtml")
   return xhtml_file

def insert_to_db(l,tbl):

   # Connect to the db as CS288 user
   db = MySQLdb.connect(host = "localhost", user="cs288", passwd="cs288pass", db = "nyse");
   
   # Handle on the db to perform operations
   handle = db.cursor()

   # Create table with rows
   create_table = "create table if not exists {} (name varchar(150), symbol  varchar(80), volume integer, price float, chng float, pchange float)".format(tbl)
   handle.execute(create_table)

   # Insert each row form dict
   for x in l:
      insert = ("insert into {} (name, symbol, volume, price, chng, pchange) values (%s, %s, %s, %s, %s, %s)").format(tbl)
      data = (x["name"], x["symbol"], x["volume"], x["price"], x["chng"], x["pchange"])
      handle.execute(insert, data)

   # Apply changes
   db.commit()

   # To be used for table display
   # return handle NOT NEEDED

def main():

   # 1st command arg: html file
   html_fn = sys.argv[1]

   # Convert x.html to x.xhtml file using java tagsoup
   xhtml_fn = html_to_xml(html_fn)

   # Create DOM tree structure
   global dom
   dom = parse(xhtml_fn)

   # Extract data into dictionary
   dict = extract_values(dom)

   # Remove .html from the filename to conform with mysql syntax
   fn = html_fn.replace('.html', '')

   # make sure your mysql server is up and running
   handle = insert_to_db(dict,fn) # fn = table name for mysql

   sys.exit(0)
   # end of main()

if __name__ == "__main__":
    main()

