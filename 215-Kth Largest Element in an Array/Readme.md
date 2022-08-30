215. Kth Largest Element in an Array

解題邏輯:  
題目要求找到第 K 大的數字，因此可以利用 quick sort 的變形來處理，quick sort 排序完一輪後，會回傳 pivot 的位置，透過 pivot 的位置可以知道這個數字是不是題目要求第 K 大的數字。  

以<sup>[3,5,3,6,2,4,5,2,1]找第 4 大的數字</sup>為例  
第一輪排序會將所有比 3 小的數字排在左邊，比 3 大的數字排在右邊，最後把 3 跟指針l和指針r相遇的值互換並且回傳 pivot 的位置。  
<pre>
[3,1,3,2,2,4,5,6,5]
 |       |
 p       l
         r
</pre>
排序完後3跟2交換。  
<pre>
[2,1,3,2,3,4,5,6,5]
</pre>
交換完畢後回傳 pivot 的位置是第 5 大的數字，由於第 4 大的數字在這個 pivot 的右邊，只要再排序右邊的陣列就好(左邊不需要再排序了)。  
<pre>
[2,1,3,2,3,4,5,6,5]
           |     |
           l     r
           p
</pre>
由於所有的數字都比 4 大，因此指針 r 指到 4 並且回傳 pivot 的位置(剛好是第 4 大的數字)。  
<pre>
[2,1,3,2,3,4,5,6,5]
           |
           l
           r
           p
</pre>
回傳答案4。  


<pre>
測試資料:
[3,2,1,5,6,4]
2
[3,5,3,6,2,4,5,2,1]
4
[3,2,3,1,2,4,5,5,6,4,21,5,1234,5,13,5,21,34,1234,1235,6,23,463,451,234,36,57,67,3,45,2345,1234]
1
</pre>