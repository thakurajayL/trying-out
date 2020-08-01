#include <iostream>
#include <queue>

int main() {
    std::priority_queue<uint32_t> job_queue;
    while(1) {
        uint32_t choice;
        uint32_t number;
        std::cout<<"1) Add number "<<std::endl;
        std::cout<<"2) Remove number "<<std::endl;
        std::cout<<"3) Display Queue "<<std::endl;
        std::cout<<"4) Quit "<<std::endl;
        std::cin>>choice;
        switch(choice)
        {
            case 1:
                std::cout<<"Enumber number to enter ";
                std::cin>>number;
                job_queue.push(number);
                break;
            case 2:
                std::cout<<"Popped number  "<<job_queue.top()<<std::endl;
                job_queue.pop();
                break;
            case 3:
                {
                std::priority_queue<uint32_t> temp_queue = job_queue;
                std::cout<<"{";
                while (!temp_queue.empty()) {
                    std::cout<<" "<<temp_queue.top();
                    temp_queue.pop();
                } 
                std::cout<<"}"<<std::endl;
                }
                break;
            case 4:
                std::cout<<"Bye bye"<<std::endl;
                return 0;
                break;
            default:
                std::cout<<"Wrong option"<<std::endl;
        }
    }
    return 0;
}
