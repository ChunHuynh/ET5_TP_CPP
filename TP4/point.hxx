

/*-------------------------------------   1.1   -------------------------------------*/
template <std::size_t dim> point<dim> createRandom(){
    assert(dim >= 1);
    point<dim> rand_point;
    for(size_t i=0; i<dim; i++){
        rand_point.coords[i] = (double) rand() / RAND_MAX;
    }
    return rand_point;
}

template <std::size_t dim>
std::ostream& operator<<(std::ostream& out, const point<dim>& p) {
    assert(dim >= 1);
    out << "(";
    out << p.coords[0];
    for(size_t i=1; i<dim; i++)
        out << ", " << p.coords[i];
    out << ")";
    
    return out;
}

/*-------------------------------------   1.3   -------------------------------------*/
template <std::size_t dim>
double dist(const point<dim>& p1, const point<dim>& p2) {
    double dist = 0.0;
    for(size_t i=0; i<dim; i++){
        dist += pow( p1.coords[i]-p2.coords[i], 2.0 );
    }
    return sqrt(dist);
}

template <std::size_t dim>
const point<dim>& closest(const points<dim>& pts, const point<dim>& p) {
    auto comp = [&p](const point<dim>& a, const point<dim>& b) { return dist(a, p) < dist(b, p); };
    return *std::min_element(pts.begin(), pts.end(), comp);
}

/*-------------------------------------   1.4   -------------------------------------*/
template <std::size_t dim>
point<dim> operator+(const point<dim>& p1, const point<dim>& p2){
    point<dim> res;
    std::transform(p1.coords, p1.coords+dim, p2.coords, res.coords, std::plus<double>());
    return res;
}

template<std::size_t dim>
point<dim> barycenter(const points<dim>& pts){

    point<dim> bary = std::accumulate(pts.begin(), pts.end(), bary);
    for (std::size_t i =0; i<dim; i++){
        bary.coords[i] = bary.coords[i]/pts.size();
    }
    return bary;
}

/*-------------------------------------   2.1   -------------------------------------*/
std::string normalize(std::string const & str){
    std::string res = str;
    sort(res.begin(), res.end());
    return res;
}

bool isAnagram(std::string const & str1, std::string const & str2){
    return normalize(str1) == normalize(str2);
}

/*-------------------------------------   2.2   -------------------------------------*/
std::vector<std::string> load(){
    std::ifstream file("wordsEn.txt"); // alternative "../wordsEn.txt"
    std::vector<std::string> words;
    std::string word;
    while(std::getline(file, word)){
        words.push_back(word);
    }

    return words;
}

/*-------------------------------------   2.3   -------------------------------------*/
dictionary convert(std::vector<std::string> const & words){
    dictionary larousse;

    for(std::size_t i=0; i<words.size(); i++){
        std::string tmp = normalize(words.at(i));
        larousse.insert({tmp, words.at(i)});
    }

    return larousse;
}

/*-------------------------------------   2.4   -------------------------------------*/
std::vector<std::string> anagrams(dictionary const & dict, std::string const & str){
    std::vector<std::string> res;

    bool exist = false;
    for (auto x : dict){
        if (x.second == str)
            exist = true;
    }

    if (!exist)
        throw new std::exception();

    std::pair <dictionary::const_iterator,dictionary::const_iterator> p = dict.equal_range(normalize(str));
    for(dictionary::const_iterator i = p.first; i != p.second; ++i){
        if(i->second != str){
            res.push_back(i->second);
        }
    }

    return res;
}