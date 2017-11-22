//
// Created by László Molnár on 2017-11-15.
//

#ifndef CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
#define CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
class LightningWordFinder
{
public:

    bool isValidCharacter(char c)
    {
        std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < validChars.size(); ++i)
        {
            if (c == validChars[i])
            {
                return true;
            }
        }
        return false;
    }

    std::string getLongestWord(const std::string& text)
    {

        std::string word = "";
        std::string buildingWord = "";

        long textLength = text.size();
        for (int i = 0; i < textLength - word.size(); ++i)
        {
            for (int j = 0; j < textLength - (i+1); ++j)
            {
                char asd = text[i+j];
                if (isValidCharacter(text[i+j]))
                {
                    buildingWord += text[i+j];
                }
                else
                {
                    if (word.size() < buildingWord.size())
                    {
                        word = buildingWord;
                    }
                    i += buildingWord.size();
                    j = textLength;
                    buildingWord = "";
                }
            }
        }

        return word;
    }
};
#endif //CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
