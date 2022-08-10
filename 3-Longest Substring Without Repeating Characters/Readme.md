3-Longest Substring Without Repeating Characters


解題邏輯:  
建立一個陣列記錄每個字母的使用情形，0代表未使用，1代表已使用。  
建立兩個指標來記錄子字串的查詢狀況，指標A指向子字串的頭，指標B往後找最長的子字串，若指標B遇到已經使用過的字母(陣列中該字母使用情形為1)，指標A開始往指標B移動，並且將陣列的使用情形改回0。  
  
例如: abcdeafgh  
  
指標A和B從第一的字母"a"開始找，指標B從abcde一直到遇到下一個a時，發現重複了(陣列中字母a的使用情形為1)。  

<pre>
abcdeafgh  
^----^  
A----B  
</pre>

這時指標A開始從abcde移動到下一個a的位址，並將陣列中abcde的使用情形改回0，接著再從指標B的位址繼續往下找。  

<pre>
abcdeafgh  
     ^--^  
     A--B  
</pre>
