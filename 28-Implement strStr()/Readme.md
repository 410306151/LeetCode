28. Implement strStr()  

解題邏輯:  
A.暴力解  
用一個迴圈跑 haystack 的每個字母，遇到 needle 的第一個字母後，進入第二個迴圈開始比對 haystack 跟 needle 每個字母是否相同。  
  
B.使用 **Knuth-Morris-Pratt** (KMP 演算法)  
假如 needle 的第一個字母出現次數大於1(假設第一個字母是a，記錄下一次出現字母 a 的位置，接著從 needle 的第二個字母開始比對，如此一來往下一個字串搜尋的時候，就可以先跳過已經比對過的字母，減少比對次數。  

舉例來說:  
haystack = <sub>"mississippi"</sub>  
needle = <sub>"issip"</sub>  
needle 裡 i 出現了兩次，因此比對 haystack 時必定會出現重複比對 i 的情形，因此第二次遇到 i 的時候(haystack 的第4個位置)，記錄這個 i 的位置(haystack[4])，讓下一次直接從第二個 i (haystack[4]開始比對 needle。  

若要跳過已經比對過的項目，以下為例子:  
haystack = <sub>"asdasdasdasdfabc"</sub>  
needle = <sub>"asdasdf"</sub>  
當 haystack 比對到 **asd _a_ sdasdasdfabc** 時，斜體字 _a_ 的後面 sd 重複出現，因此下次比對時，我們就從 ~~asdasd~~ _a_ sdasdfabc 與 ~~asd~~ _a_ sdf 開始比對。  
  
<pre>
測試資料:
"hello"
"ll"
"fbvsnjrgoqiefwoijadnlkhaewlnfhlnfwuincrhiehpewmfdshjnzlcijohjrqwoeihbujfedifolakf"
"nfwuincrhi"
"zxcvbn"
"zxca"
"asdasdasdasdfabc"
"asdasdf"
"mississippi"
"issip"
"babbbbbabb"
"bbab"
</pre>
