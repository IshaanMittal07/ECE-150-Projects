#include <iostream>
#include <cmath>

// Resrouces: https://cplusplus.com/forum/beginner/9273/

int main();

bool validateMax(double number)
{
    while (true)
    {
        if (number == std::round(number) && number > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool validate(double number, double numberMax)
{
    while (true)
    {
        if (number >= 0 && number <= numberMax)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

double calc(double number, double max)
{
    double grade = (number / max) * 100;
    return grade;
}

double finalGrade(double exam, double proj)
{
    if (exam <= 40)
    {
        return exam;
    }

    else if (exam >= 60)
    {
        double calc = ((2.0 / 3.0 * exam) + (1.0 / 3.0 * proj));
        return calc;
    }

    else if (exam > 40 && exam < 60)
    {
        return proj * (((exam - 40)) / 60) + exam * (1 - ((exam - 40) / 60));
    }

    else 
    {
        return 0.0;
    }
}

int main()
{
    double final{};
    double finalMax{};
    double finalMark{};

    double midterm{};
    double midtermMax{};
    double midtermGrade{};

    double proj1{};
    double proj1Max{};
    double proj1Grade{};

    double proj2{};
    double proj2Max{};
    double proj2Grade{};

    double proj3{};
    double proj3Max{};
    double proj3Grade{};

    double proj4{};
    double proj4Max{};
    double proj4Grade{};

    double proj5{};
    double proj5Max{};
    double proj5Grade{};

    double weightAvg{};
    double projAvg{};

    std::string finalMaxInput{"Enter the maximum grade on the final examination: "};
    std::string finalInput{"Enter your grade on the final examination: "};

    std::string midtermMaxInput{"Enter the maximum grade on the mid-term examination: "};
    std::string midtermInput{"Enter your grade on the mid-term examination: "};

    std::string proj1MaxInput{"Enter the maximum grade on project 1: "};
    std::string proj1Input{"Enter your grade on the project 1: "};

    std::string proj2MaxInput{"Enter the maximum grade on project 2: "};
    std::string proj2Input{"Enter your grade on the project 2: "};

    std::string proj3MaxInput{"Enter the maximum grade on project 3: "};
    std::string proj3Input{"Enter your grade on the project 3: "};

    std::string proj4MaxInput{"Enter the maximum grade on project 4: "};
    std::string proj4Input{"Enter your grade on the project 4: "};

    std::string proj5MaxInput{"Enter the maximum grade on project 5: "};
    std::string proj5Input{"Enter your grade on the project 5: "};

    // TRY TO MAKE THIS MORE EFFICIENT LATER
    //  FINAL
    std::cout << finalMaxInput;
    std::cin >> finalMax;
    while (true)
    {

        if (validateMax(finalMax))
        {
            break;
        }

        else
        {
            std::cout << finalMaxInput;
            std::cin >> finalMax;
        }
    }

    std::cout << finalInput;
    std::cin >> final;
    while (true)
    {

        if (validate(final, finalMax))
        {
            break;
        }

        else
        {
            std::cout << finalInput;
            std::cin >> final;
        }
    }

    // MIDTERM
    std::cout << midtermMaxInput;
    std::cin >> midtermMax;
    while (true)
    {

        if (validateMax(midtermMax))
        {
            break;
        }

        else
        {
            std::cout << midtermMaxInput;
            std::cin >> midtermMax;
        }
    }

    std::cout << midtermInput;
    std::cin >> midterm;
    while (true)
    {

        if (validate(midterm, midtermMax))
        {
            break;
        }

        else
        {
            std::cout << midtermInput;
            std::cin >> midterm;
        }
    }

    // PROJECT 1
    std::cout << proj1MaxInput;
    std::cin >> proj1Max;
    while (true)
    {

        if (validateMax(proj1Max))
        {
            break;
        }

        else
        {
            std::cout << proj1MaxInput;
            std::cin >> proj1Max;
        }
    }

    std::cout << proj1Input;
    std::cin >> proj1;
    while (true)
    {

        if (validate(proj1, proj1Max))
        {
            break;
        }

        else
        {
            std::cout << proj1Input;
            std::cin >> proj1;
        }
    }

    // PROJECT 2
    std::cout << proj2MaxInput;
    std::cin >> proj2Max;
    while (true)
    {

        if (validateMax(proj2Max))
        {
            break;
        }

        else
        {
            std::cout << proj2MaxInput;
            std::cin >> proj2Max;
        }
    }

    std::cout << proj2Input;
    std::cin >> proj2;
    while (true)
    {

        if (validate(proj2, proj2Max))
        {
            break;
        }

        else
        {
            std::cout << proj2Input;
            std::cin >> proj2;
        }
    }

    // PROJECT 3
    std::cout << proj3MaxInput;
    std::cin >> proj3Max;
    while (true)
    {

        if (validateMax(proj3Max))
        {
            break;
        }

        else
        {
            std::cout << proj3MaxInput;
            std::cin >> proj3Max;
        }
    }

    std::cout << proj3Input;
    std::cin >> proj3;
    while (true)
    {

        if (validate(proj3, proj3Max))
        {
            break;
        }

        else
        {
            std::cout << proj3Input;
            std::cin >> proj3;
        }
    }

    // PROJECT 4
    std::cout << proj4MaxInput;
    std::cin >> proj4Max;
    while (true)
    {

        if (validateMax(proj4Max))
        {
            break;
        }

        else
        {
            std::cout << proj4MaxInput;
            std::cin >> proj4Max;
        }
    }

    std::cout << proj4Input;
    std::cin >> proj4;
    while (true)
    {

        if (validate(proj4, proj4Max))
        {
            break;
        }

        else
        {
            std::cout << proj4Input;
            std::cin >> proj4;
        }
    }

    // PROJECT 5
    std::cout << proj5MaxInput;
    std::cin >> proj5Max;
    while (true)
    {

        if (validateMax(proj5Max))
        {
            break;
        }

        else
        {
            std::cout << proj5MaxInput;
            std::cin >> proj5Max;
        }
    }

    std::cout << proj5Input;
    std::cin >> proj5;
    while (true)
    {

        if (validate(proj5, proj5Max))
        {
            break;
        }

        else
        {
            std::cout << proj5Input;
            std::cin >> proj5;
        }
    }

    finalMark = calc(final, finalMax);
    midtermGrade = calc(midterm, midtermMax);
    proj1Grade = calc(proj1, proj1Max);
    proj2Grade = calc(proj2, proj2Max);
    proj3Grade = calc(proj3, proj3Max);
    proj4Grade = calc(proj4, proj4Max);
    proj5Grade = calc(proj5, proj5Max);

    if (finalMark > midtermGrade)
    {
        midtermGrade = finalMark;
    }
    if (finalMark > proj1Grade)
    {
        proj1Grade = finalMark;
    }
    if (finalMark > proj2Grade)
    {
        proj2Grade = finalMark;
    }
    if (finalMark > proj3Grade)
    {
        proj3Grade = finalMark;
    }
    if (finalMark > proj4Grade)
    {
        proj4Grade = finalMark;
    }
    if (finalMark > proj5Grade)
    {
        proj5Grade = finalMark;
    }
    
    weightAvg = (3.0 / 4.0 * finalMark) + (1.0 / 4.0 * midtermGrade);

    double grade{};
    projAvg = (proj1Grade + proj2Grade + proj3Grade + proj4Grade + proj5Grade) / 5.0;
    grade = finalGrade(weightAvg, projAvg);
    grade = std::round(grade + 1e-12);
    std::cout << "You final grade is: " << grade << std::endl;

    return 0;
}