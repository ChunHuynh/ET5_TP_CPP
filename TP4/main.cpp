#include "point.h"

int main() {
    srand(time(NULL));
    std::cout << "\n---- 1.1 ----\n";
    std::cout << "Random point:\n" <<createRandom<3>() << "\n";
    
    std::cout << "\n---- 1.2 ----\n";
    std::cout << "Vector of random points:\n";
    points<2> rand_points;
    std::generate_n(std::back_inserter(rand_points), 5, createRandom<2>);
    std::for_each(rand_points.begin(), rand_points.end(), [](const point<2>& p){ std::cout << p << "\n"; });
    
    std::cout << "\n---- 1.3 ----\n";
    point<2> p= { .coords = {0.5, 0.5} };
    std::cout << "Closest to (0.5, 0.5):\n" << closest(rand_points, p) << "\n";
    
    std::cout << "\n---- 1.4 ----\n";
    std::cout << "Barycenter:" << barycenter(rand_points) << "\n";

    std::cout << "\n---- 2.1 ----\n";
    std::cout << "Normalize \"onirique\" : " << normalize("onirique") << "\n";
    std::cout << "\"onirique\" & \"ironique\" anagram? : " << isAnagram("onirique", "ironique") << "\n";
    std::cout << "\"patate\"   & \"carotte\"  anagram? : " << isAnagram("patate", "carotte") << "\n";

    std::cout << "\n---- 2.2 ----\n";
    std::vector<std::string> words = load();
    std::cout << "Number of words : " << words.size()
              << "\nLast word : " << words.at(words.size() - 1) << "\n";

    std::cout << "\n---- 2.3 ----\n";
    dictionary dict = convert(words);
    std::string word_to_find = "dictionary";
    dictionary::const_iterator got = dict.find(normalize(word_to_find));

    if (got == dict.end())
        std::cout << "Word " << word_to_find << " not found\n";
    else
        std::cout << "Found : " << got->first << " is " << got->second << "\n";

    std::cout << "\n---- 2.4 ----\n";
    std::vector<std::string> test_words = { "anagram", "parrot", "abba", "insert", "silent" };
    std::vector<std::string> ana;
    for(auto w:test_words){
        std::cout << "Anagrams of " << w << ":\n";
        try {
             ana = anagrams(dict, w);
        } catch (...) {
            std::cout << w << " does not exist in dictionary.\n\n";
            continue;
        }

        for(auto a:ana){
            std::cout << a << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "\n---- 2.5 ----\n";
    auto it = std::max_element(words.begin(), words.end(),
                               [&dict](std::string& a, std::string& b)
                               { return dict.count(normalize(a)) < dict.count(normalize(b)); });

    std::cout << "Word with the most anagram: " << *it << "\n";
    ana = anagrams(dict, *it);
    for(auto a:ana){
        std::cout << a << "\n";
    }

    std::cout << "\nList of words beginning with \'l\', with 4 letters and no anagram:\n";
    std::copy_if(words.begin(), words.end(),
                 std::ostream_iterator<std::string>(std::cout, "\n"),
                 [&dict](std::string& word)
                 { return word.size() == 4 &&
                          word.at(0) == 'l' &&
                          dict.count(normalize(word)) == 1; });

    return 0;
}




