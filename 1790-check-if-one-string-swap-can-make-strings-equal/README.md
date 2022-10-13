<h2><a href="https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/">1790. Check if One String Swap Can Make Strings Equal</a></h2><h3>Easy</h3><hr><div><p>You are given two strings <code>s1</code> and <code>s2</code> of equal length. A <strong>string swap</strong> is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.</p>

<p>Return <code>true</code> <em>if it is possible to make both strings equal by performing <strong>at most one string swap </strong>on <strong>exactly one</strong> of the strings. </em>Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "bank", s2 = "kanb"
<strong>Output:</strong> true
<strong>Explanation:</strong> For example, swap the first character with the last character of s2 to make "bank".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "attack", s2 = "defend"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make them equal with one string swap.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s1 = "kelb", s2 = "kelb"
<strong>Output:</strong> true
<strong>Explanation:</strong> The two strings are already equal, so no string swap operation is required.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li><code>s1</code> and <code>s2</code> consist of only lowercase English letters.</li>
</ul>
</div>

---
<span style="color:yellow">솔루션.</span>
<h3>1. 모든 경우의 수 탐색 (brute force)  || 시간 복잡도 : O(N^2)</h3>

문자열의 길이는 서로 같으며 최대 100 밖에 안되다보니, 그냥 일일이 swap 해가면서 모든 경우에 대해서 조사하는 방법을 구현하였다. s2 에 대해서 swap 을 할 수 있는 경우를 모두 탐색하는데, s1==s2 인 경우에 true 를 반환해주도록 하였다. 이 방식은 O(N^2) 의 시간복잡도를 가지며, N 이 최대 100 이므로 TLE 가 발생하지 않을 것이라 예상하였고, 제출해보니 넉넉하게 통과하는 것을 확인할 수 있었다.


<h3>2. 문자열 빈도수와 mismatch position 의 개수에 따른 풀이법 || 시간 복잡도 : O(N)</h3>

1 번 방식으로 무식하게 푼 뒤에, 해당 문제의 discussion page 를 둘러보면서 아래의 풀이 방법을 찾았다. 기본적으로 s1, s2 가 서로 AlmostEqual 이려면 알파벳 구성이 동일하다는 전제 하에 mismatched position 의 개수가 0 개이거나 2개여야 한다. 예를 들어 input 이 bank, kanb 라고 하자. 먼저 두 문자열의 알파벳 구성은 동일하다. 그리고 mismatched position 은 2개이므로 AlmostEqual 하다. input 이 bank, bank 라면 mismatched position 은 0 개이므로 당연히 AlmostEqual 하다. mismatched position 이 0 개도 아니고 2개도 아니라면, 1 번의 swap 으로 두 문자열이 일치하게 되는 경우는 절대 없음을 직감할 수 있다. 그러므로 우리는 2 가지만 체크하면 된다.

 

(A) 두 문자열이 동일한 문자 구성을 가지고 있는가?

(B) 그렇다면 mismatched poistion 의 개수가 0개 혹은 2개인가?

 

A 를 위해서 hashset 을 이용해도 되겠지만, 그냥 알파벳 개수만큼의 빈 vector 을 선언해놓고 반복문을 돌며 arr[s[i]-'a' ]++, rr[s2[i]-'a']-- 를 수행해주는 방식을 택하였다. 만약 arr 배열 상에 0이 아닌 원소가 존재한다면 곧바로 false 를 반환해주면 된다. 왜냐면 알파벳 빈도수가 다르다는 것은 어떻게 배열을 바꾸어도 두 문자열이 일치할 수 없기 때문이다.

 

위 과정을 거친 뒤에는 mismatched position 의 개수를 검사한다. 그리고 최종적으로 그 개수가 0개 혹은 2개이면 true 를, 아니면 false 를 반환해주면 된다. 
