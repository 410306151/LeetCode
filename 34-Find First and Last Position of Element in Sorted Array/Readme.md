34. Find First and Last Position of Element in Sorted Array

解題邏輯:  
使用 Binary search 找出和 target 相符的位置，在遞迴判斷當前的值是否超出 target 的範圍，避免搜尋整個陣列而變成 O(n)。
時間複雜度: O(logn)

註: 另一種方法是用 Binary search 找到 target 的位置後，從兩側往外延伸找到範圍。

<pre>
測試資料:
[5,7,7,8,8,10]
8
[1]
1
[1]
2
[]
8
[1,2]
1
[1,2]
2
[1,2]
3
[1,2,3]
1
</pre>
