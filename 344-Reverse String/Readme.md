344. Reverse String  

解題邏輯:  
使用兩個 index h 和 t，分別從字串的頭跟尾開始執行交換，一直到 h 和 t 相遇或交錯即可停止。  
<pre>
abcde
^---^
h   t 交換

ebcda
 ^-^
 h t 交換

edcba
  ^
  h
  t 相遇
</pre>


<pre>
測試資料:
["h","e","l","l","o"]
["a"]
["a","b","b","a"]
["a","b","a"]
</pre>
