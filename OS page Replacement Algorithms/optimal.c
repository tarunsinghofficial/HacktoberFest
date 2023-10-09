#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

int findOptimalPage(vector<int>& pages, vector<int>& frames, int startIndex) {
    int pageToReplace = -1;
    int farthestUse = INT_MIN;

    for (int i = 0; i < frames.size(); i++) {
        int currentPage = frames[i];
        int nextPageIndex = -1;

        for (int j = startIndex + 1; j < pages.size(); j++) {
            if (pages[j] == currentPage) {
                nextPageIndex = j;
                break;
            }
        }

        if (nextPageIndex == -1) {
            return i; // If a page won't be used again, replace it.
        }

        if (nextPageIndex > farthestUse) {
            farthestUse = nextPageIndex;
            pageToReplace = i;
        }
    }

    return pageToReplace;
}

int main() {
    int numFrames;
    cout << "Enter the number of page frames: ";
    cin >> numFrames;

    vector<int> pages;
    cout << "Enter the sequence of page references (end with -1):\n";
    int page;
    while (cin >> page && page != -1) {
        pages.push_back(page);
    }

    vector<int> frames(numFrames, -1); // Initialize frames with -1 indicating empty slots

    int pageFaults = 0;
    int startIndex = -1;

    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];

        // Check if the page is already in a frame
        auto it = find(frames.begin(), frames.end(), currentPage);

        if (it == frames.end()) {
            // Page fault
            pageFaults++;
            int replaceIndex = findOptimalPage(pages, frames, i);
            frames[replaceIndex] = currentPage;
        }

        startIndex++;
    }

    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
