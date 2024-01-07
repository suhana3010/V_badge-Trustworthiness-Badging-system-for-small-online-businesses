# V_badge-Trustworthiness-Badging-system-for-small-online-businesses
c++ code
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

 using namespace std;

int main() {
    unordered_map<string, int> wordMap;

    // Populate the map with good and bad words
      //negative comments for sentiment analysis
    wordMap["good"] = 1;
    wordMap["positive"] = 1;
    wordMap["better quality"] = 1;
    wordMap["decent quality"] = 1;
    wordMap["love that"] = 1;
    wordMap["cute"] = 1;
    wordMap["Unique"] = 1;
    wordMap["Amazing"] = 1;
    wordMap["Variety"] = 1;
    wordMap["best"] = 1;
    wordMap["surprised"] = 1;
    wordMap["perfectly"] = 1;
    wordMap["top notch"] = 1;
    wordMap["fabulous"] = 1;
    wordMap["fantastic"] = 1;
    wordMap["genuine"] = 1;
    wordMap["huge discounts"] = 1;
    wordMap["not fraud offline"] = 1;
    wordMap["fan"] = 1;
    wordMap["satisfaction of customer"] = 1;
    wordMap["Doesnt tarnish"] = 1;

    //negative comments for sentiment analysis

    wordMap["poor"] = -1;
    wordMap["bad"] = -1;
    wordMap["unimpressed"] = -1;
    wordMap["not positive"] = -1;
    wordMap["doesn't last long"] = -1;
    wordMap["scammers"] = -1;
    wordMap["risky"] = -1;
    wordMap["expensive"] = -1;
    wordMap["worst"] = -1;
    wordMap["average"] = -1;
    wordMap["no update"] = -1;
    wordMap["inconvenient"] = -1;
    wordMap["hassle"] = -1;
    wordMap["cheap quality"] = -1;
    wordMap["poor quality"] = -1;
    wordMap["refuses"] = -1;
    wordMap["fraudster"] = -1;
    wordMap["scam"] = -1;
    wordMap["file a case"] = -1;
    wordMap["negligent"] = -1;
    wordMap["consumer complaint"] = -1;
    wordMap["late delivery"] = -1;
    wordMap["slow"] = -1;
    wordMap["waste of money"] = -1;
    wordMap["wouldn't reply"] = -1;
    wordMap["not user friendly"] = -1;
    wordMap["cannot return"] = -1;
    wordMap["issues with sizing"] = -1;
    wordMap["fraud"] = -1;
    wordMap["scamming"] = -1;
    wordMap["not responding"] = -1;
    wordMap["not returning"] = -1;
    wordMap["legal action"] = -1;
    wordMap["unprofessionalism"] = -1;
    wordMap["reported cheated"] = -1;
    wordMap["fake"] = -1;
    wordMap["satisfaction of customer"] = -1;



    // Vector to store reviews for small businesses under different sectors
    unordered_map<string, vector<string>> businessReviews{
        {"sector--------------------->business name", {"1. quality is average", "2. pretty good", "3. pleasantly surprised","4. still haven't received my product","5. worst customer service","6. no update"}},
        {"sector--------------------->business name ", {"1. good quality", "2. fit perfectly!", "so comfortable", "3. stain on it", "4. returning/exchanging process is so inconvenient", "5. exchange process is a hassle", "6. cheap quality", "7. bonkers quality is top notch"}},
        {"sector--------------------->"business name", {"1. I didn't like", "2. poor quality", "3. not affordable", "4. absolute worst"}},
        {"sector--------------------->business name", {"1. refuses to answer", "2. fraudster", "3. scam", "4. File a case against her", "5. report her", "6. negligent", "7. raised a consumer complaint earlier!", "8. complete scammer"}},
        {"sector--------------------->business name. ", {"1. customer service is extremely slow", "2. delivery was late", "3. worst", "4. quality is very very average", "5. waste of money tbh", "6. customer service was soooooooo bad.", "7. wouldn't reply to my dms", "8. very average"}},
        {"sector--------------------->business name", {"1. looked cheaper", "2. return, exchange policy are not user friendly", "3. cannot return the product", "4. it looks fabulous"}},
        {"sector"--------------------->business name ", {"1. quality is super cheap", "2. issues with sizing", "3. it was fantastic."}},
  nt multiple things to wear on different occasions for cheap, i'd say go for it. ", "2. tarnished after 3 uses", "3. silver necklace's quality is far better"}},
    cout<<"                                   ********           \n";
    cout<<"                                                SMALL BUSINESSES AVAILABLE ONLINE                        \n";
    cout<<"                                   ********          \n";
    cout<<"\n";
    cout<<"Empower your choices with data! V_badges analyzes reviews to give you a clear picture of small online brands. Uncover the positives and negatives before you shop. Knowledge is shopping power!\n";
    cout<<"\n";
    cout<<"These are the various sector where you can explore various online brands.\n";
    cout<<" Clothing brands \n";
    cout<<" Jewellery brands  \n";
    cout<<" Services          \n";
    cout<<"\n";
    cout<<"   SECTORS                                BRANDS \n";
    cout<<"\n";
    //to Display available businesses for the selected sector
    int index = 1;
    for (const auto& business : businessReviews) {
        cout << index << ". " << business.first << "\n";
        index++;
    }

    // User input for business
    cout << "Choose a brand, you want to know about it before buying its product  (1-" << businessReviews.size() << "): ";
    int businessChoice;
    cin >> businessChoice;

    if (businessChoice < 1 || businessChoice > businessReviews.size()) {
        cerr << "Invalid business choice." << endl;
        return 1;
    }

    // Display reviews for the selected business
    cout << "Reviews for selected business:\n";
    const auto& selectedBusiness = next(businessReviews.begin(), businessChoice - 1);
    for (const auto& review : selectedBusiness->second) {
        cout << review << "\n";
    }

    // scores for all reviews under the selected business
    int totalPositiveScore = 0;
    int totalNegativeScore = 0;

    for (const auto& review : selectedBusiness->second) {
        istringstream iss(review);
        string word;
        int positiveScore = 0;
        int negativeScore = 0;

        while (iss >> word) {
            if (wordMap.find(word) != wordMap.end()) {
                if (wordMap[word] > 0) {
                    positiveScore++;
                } else {
                    negativeScore++;
                }
            }
        }

        // Aggregate scores for the entire review
        totalPositiveScore += positiveScore;
        totalNegativeScore += negativeScore;
    }
    // percentages based on the total number of reviews
int totalReviews = selectedBusiness->second.size();

double positivePercentage = (static_cast<double>(totalPositiveScore) / (totalPositiveScore+totalNegativeScore) )* 100;
double negativePercentage = (static_cast<double>(totalNegativeScore) / (totalPositiveScore+totalNegativeScore))* 100;

    // displaying separate scores
    cout << "\nPositive Percentage: " << positivePercentage << "%" << endl;
    cout << "Negative Percentage: " << negativePercentage << "%" << endl;

    // Providing V_BADGE based on positive percentage
if (positivePercentage >= 60.0) {
    cout << "We award a Verification Badge/V_Badge, indicating our acknowledgment of this business's authenticity."<<endl;
    cout << "Based on our assessment, approximately 60% of the reviews received are positive, reinforcing our belief in its status as a genuine small business." << endl;
} else {
    cout << "We refrain from awarding a Verification Badge (V_badge) since, according to our calculations." << endl;
    cout<< "The business does not meet the criterion of having over 60% positive comments. " << endl;
}

    return 0;
}
