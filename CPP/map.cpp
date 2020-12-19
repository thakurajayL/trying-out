#include <iostream>
#include <map>

struct transKey {
    uint32_t src_port;
    uint32_t src_ip;
    uint32_t seq_num;
};
typedef struct transKey transKey_t;

struct comp
{
    bool operator()(const struct transKey &lhs, const struct transKey &rhs) const
    {
        std::cout<<std::endl<<"**Compare function called "<<std::endl;
        if(lhs.src_port == rhs.src_port)
        {
            std::cout<<"Port Match found "<<std::endl;
            if(lhs.src_ip == rhs.src_ip)
            {
                std::cout<<"Source Match found "<<std::endl;
                if(lhs.seq_num == rhs.seq_num)
                {
                    std::cout<<"Seq num Match found "<<std::endl;
                    return false;
                }
                std::cout<<"seq num not matched "<<std::endl;
                return lhs.seq_num < rhs.seq_num;
            }
            std::cout<<"IP address not matched "<<std::endl;
            return lhs.src_ip < rhs.src_ip;
        }
        std::cout<<"port number not matched "<<std::endl;
        return lhs.src_port < rhs.src_port;
    }
};

int main()
{
    std::map<transKey_t,void *, comp> mymap;

    {
        transKey_t k1 = { 1, 1, 1};
        void *p1 = (void *)&k1;
        std::pair <transKey_t,void*> foo;
        foo = std::make_pair(k1, p1);
        std::cout<<"adding 1,1,1"<<std::endl;
        mymap.insert(foo);
    }
    {
        transKey_t k1 = { 2, 2, 2};
        void *p1 = (void *)&k1;
        std::pair <transKey_t,void*> foo;
        foo = std::make_pair(k1, p1);
        std::cout<<"adding 2,2,2"<<std::endl;
        mymap.insert(foo);
    }
    {
        transKey_t k1 = { 3, 3, 3};
        void *p1 = (void *)&k1;
        std::pair <transKey_t,void*> foo;
        foo = std::make_pair(k1, p1);
        std::cout<<"adding 3,3,3"<<std::endl;
        mymap.insert(foo);
    }
    {
        transKey_t k1 = { 4, 1, 2};
        void *p1 = (void *)&k1;
        std::pair <transKey_t,void*> foo;
        foo = std::make_pair(k1, p1);
        std::cout<<"adding 4,1,2"<<std::endl;
        mymap.insert(foo);
    }

    std::map<transKey_t, void* >::iterator it = mymap.begin();
    for (; it != mymap.end(); it++)
    {
        std::cout << "Port "<<it->first.src_port<<" addr "<<it->first.src_ip << " seq "<< it->first.seq_num<< "Value - "<<it->second << std::endl;
    }

    {
        std::map<transKey_t, void*>::iterator it = mymap.begin();
        transKey_t k1 = { 2, 2, 2};
        std::cout<<"Search key 2,2,2 "<<std::endl;
        it = mymap.find(k1);
        if(it == mymap.end())
        {
            std::cout<<"Key not Found"<<std::endl;
        }
        else
        {
            std::cout<<"Key Found - it->second "<<it->second<<std::endl;
        }
    }
    return 0;
}
