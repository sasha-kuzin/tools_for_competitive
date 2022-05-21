# Competitive programming storage
### topics
- [Introduction](#introduction)
- [Structure and navigation](#structure-and-navigation)
- [Storage server](#storage-server)
- [Code generator](#code-generator)

## Introduction
Here are my storage for short solutions of algorythmic problems from leetcode(medium+) and competitive problems from several platforms

At the moment I am going to start with primitive storage that 
is organized and maintained manually by a user (myself). But there are several directions of improvement:

<details>
<summary>Improve storage automation </summary>
Its okay to just keep your old solutions, but not enough if you want 
to reuse them. Even an average competitive programmer solves about 2-3 thousands of problems 
and many ideas are reused. For example, I often think "Oh, I solved something like this long time ago! 
I wish I could check how I did it that time, but don't remember anything about problem itself!".
Some tags for common algorythms, structures and approaches help user to find old solution, probably, several of them.
  
Another part of the improvement is solutions addition automation. Since we have tags, partition, different platform names etc, it is very boring to do this stuff manually. The first idea is to use platform's api, e.g. codeforces.com. All problems from this platform have their own tags and usually they are correct. The second idea is develop such a tool for adding new solutions (actually, it is kinda big challenge itself, but I am villing to do it so I will investigate this)
</details>

<details>
<summary>Create generator for submissions </summary>
Another side of the same problem is the fact that when we type new solution, we reuse about 50% of code. Usually I just do it, because it is hardly possible to copy/paste old implementation, there are always small difference between them. But it is possible to make several templates for common actions (popular data structures, input etc.) and store it in separate .h/.hpp files
  
But we cannot send several files as a solution. So we need to join all of them in one .cpp file, which will be compiled on the servers, so this file should have only language's standart library tools. 
  
So the purpose of the generator is parse main.cpp, find all user's headers an libraries, compose all of them in one file, remove duplications etc. and bring one ready-to-solve file to user.
</details>

<details>
<summary>Testing subsystem</summary>
Usually conestants (at least, I) don't test a lot their solutins before the submissions. But ~~almost always~~ sometimes solution don't pass all tests and we have to debug it. It is very overengineered to use something like gtest for it, but it is good to have small script which just run your main.cpp with some input and check output. Also sometimes you want to check your solution with a hundred tests with random input (e.g. the input data is random, but obeys some general rule) and you have another solution (as usual - correct but slow) as a checker. Automate this would be a great help
</details>

[back to topics](#topics)
## Structure and Navigation

**Important:** at the moment folders' structure is maintained manually. Once I implement automatic storage, this structure will be configured by a user 
and maintained automaticaly. So we can assume that my manual maintenance is such a testing process, a try to find hints and challenges for future configuration
At the moment storage is just a folder hierarchy for manual storing the code, but I would like to prepare for the future 
challenges and prepare some instructions:

 - Each file should be stored with certain path. Each folder from the level to level from the root describe certain criteria
 - Criterias should be [static](#static-criteria) and [unique](#unique-criteria)
 - Dynamic and non-unique criterias will be described during the next iteration

### static criteria

I assume that static criteria means some characteristic of the file with code which will not be changed in future. E.g. programming language

### unique criteria

I assume that unique criteria means that if a file is characterized by any criterion, it cannot be evaluated otherwise by the same criterion at the same time. E.g. if we say "this code is C++ code" we cannot say "this code is Python code" at the same time

<details>
<summary>Under the cut you can read my briefly overview on it</summary>
The main idea is store all information about code (language, origin problem, tags etc.) in separate file.
Since I am going to introduce such a storage server that it's main responsebility is filtration and 
representation files by some criterias, it had better to store this stuff separately. 
From the other side, I may want to grab some files manually, 
and it is not handy to look throw the list of dozens files. 

I assume that some criterias are static and unique. For example, programming language. 
We can be sure that any solution is written by exactly one language. 
Also we know that solution doesn't "change" its language, so if we introduce separate folders for each 
language which we use, we can say "ok, once we put a file in this folder, we never move it to another"

From the other side, some criterias are not unique and may be changed anytime. 
For example, I am going to use tags that describe what kind of problem is it. 
I put tags "dynamic programming" and "combinatorics" so if I create folders for tags I have 
to store this file twice. Finally, I can figure out that this solution dosen't use 
"dynamic programming" but use "greedy" and in case this tag affect on file location I should move 
this file in another folder

As the result I assume that criterias such tags, hints etc. should be stored separatly for 
storage server and must not affect on file location.

The last important thing is stability for "static" criterias. If I distinct programming language, 
website with origin problem and problem status (lets assume that it's important for me to store successful submits
and failed ones separately) I expect if a.cpp is successful submit for codeforce's problem on C++ and b.py 
is failed try for LeetCode problem then pathes are corresponds such a pattern like Language/Platform/Result/FileName: 
C++/codeforces/success/a.cpp and python/lettcode/failed/b/py.
</details>

Now any user can organize hierarchy as he likes (because actually we have no any platform). Further perspective is to automate this step and let the storage server to keep the content.

[back to topics](#topics)
## Storage server

**Important:** Planning is in progress, this section contains only ideas and rough plans

The main idea is to create a storage for large amount of short solutions of algorithmic problems with a support for advanced search. 

At the moment I am thinking about following questions:

 - how to make installator for this (have no experience)
 - describe vocabulary (I should essentially describe all terms: criteria, tag etc.)
 - how to run server as a service (separate permament thread) for Windows and Linux both

General plan is:
- create installator: installator should create folders hierarchy based on config file, run the service and instal the client
- create client app with adding/editing/deliting functionality
- automate the process of adding tags, criterias, target folder for storing files

Since I am doing it one step at a time, more details will come further.

Further plan is to think about web-client and browser-extension.

[back to topics](#topics)
## Code generator

**Important:** Planning is in progress, this section contains only ideas and rough plans

The main idea is to create a collection of templates in c++ and script for composing source code and all included templates 

<details>
<summary>Detailed explanation of this problem under the cur</summary>
When you participate such a programming contest, grader usually can take only one file with your code as a solution. However, 
we have a lot of popular data-structures and algorithms which we have to just retype or copy-paste manually.

It is ok to type all the code manually when you participate major contest like Google CodeJam or ICPC, but when you just train it is very boring.

Thinking about this, I decided to create a collection of templates and such a script for composing all templates and source code in one .cpp file which I can send to testing system
</details>

The first steps to develop this system:
- define some templates
- create parser. That parser should parse source code into tokens, define all included templates, remove duplication, resolve cross-dependencies and create the result file
- create client. Probably, we just need such a python script or .bat scenario, the main thing is parser which can beused as a dinamic or static library

[back to topics](#topics)
