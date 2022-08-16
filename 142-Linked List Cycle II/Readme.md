142. Linked List Cycle II

解題邏輯:  
使用 **Floyd's Cycle Detection**(或稱**龜兔賽跑演算法**)找到龜兔會合的地點後，兔子退回起點改成一格方式起跑，烏龜在會合點也用一格起跑，兩者相交的地點即為 cycle 的起點。

<pre>
測試資料:
[3,2,0,-4]
1
[]
-1
[1]
-1
[1,2]
0
[1,2,3,4,5]
1
[1,2,3,4,5]
2
[1,2,3,4,5]
3
[1,2,3,4,5]
4
</pre>