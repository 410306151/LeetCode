33. Search in Rotated Sorted Array  

解題邏輯:  
這題有偷吃步的方法讓測資通過，先判斷陣列是否有旋轉，旋轉的位置又在哪裡，再把陣列丟進 binary search 搜尋，但是這麼做時間複雜度為O(n)。  
如果要將時間複雜度壓在 O(logn)的話，需要在 binary search 的過程中判斷陣列是否有旋轉，最後才使用正規的 binary search 進行搜尋。

以下用幾個情境作為例子：  
<pre>
陣列有旋轉、中間值較大、目標在陣列右半邊
[4,5,6,7,0,1,2]
target = 0
target < left && mid > right
</pre>  
<pre>
陣列有旋轉、中間值較小、目標在陣列右半邊
[6,7,8,9,1,2,3,4,5]
target = 4
target > mid && target < left
</pre>
<pre>
陣列有旋轉、中間值較大、目標在陣列左半邊
[4,5,6,7,0,1,2]
target = 5
target < mid && target > right
</pre>
<pre>
陣列有旋轉、中間值較小、目標在陣列左半邊
[6,7,8,9,1,2,3,4,5]
target = 7
target > right && mid < right
</pre>
<pre>
陣列無旋轉，正常使用 binary search
[1,2,3,4,5,6,7,8,9]
target = 6
</pre>

<pre>
測試資料:
[4,5,6,7,0,1,2]
0
[4,5,6,7,0,1,2]
3
[1]
0
[1,2,3,4,5,6,7,8,9]
6
[1,2,3,4,5,6,7,8,9]
10
[3,1]
1
[6,7,8,9,1,2,3,4,5]
4
[1,3]
0
</pre>
