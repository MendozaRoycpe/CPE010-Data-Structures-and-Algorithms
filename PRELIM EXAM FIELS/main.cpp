//
// Created by royga on 8/27/2026.
//

    // push/enqueue each character<- combine them(thanks twain for the idea)
    for (char c : str) {
        s.push(c);
        q.enqueue(c);
    }

    // compare stack pop vs queue dequeue
    while (!s.isEmpty() && !q.empty()) {
        char fromStack = s.pop();
        char fromQueue = q.dequeue();
        if (fromStack != fromQueue) return false;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    if (isPalindrome(input))
        std::cout << input << " is a Palindrome\n";
    else
        std::cout << input << " is NOT a Palindrome\n";

    return 0;
}