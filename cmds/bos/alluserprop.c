
void alluser_prop_all(string arg1,string arg2);
private int is_running=0;
int main(object me,string arg)
{
    if(is_running>0)
    {
        write("top10�������С�\n");
        return 1;
    }
    if(!arg || arg=="")
    {
        write("alluserprop <����>\n");
        return 1;
    }
    alluser_prop_all(arg,"");
    return 1;
}

void alluser_prop_all(string arg1,string arg2)
{
    is_running=1;
    call_out("alluser_prop",0,arg1,arg2,"a");
}

string fill_space(string str,int n)
{
    int l=sizeof(str);
    int i;
    string tmp = "";
    for(i=l;i<n;i++)
        tmp+=" ";
    return tmp;
}
void alluser_prop(string arg1,string arg2,string head)
{
    string dir;
    object user;
    int i;
    string *files,file;
    dir = DATA_DIR+"user/"+head+"/";
    files = get_dir(dir+"/*.o");
    for(i=0;i<sizeof(files);i++)
    {
        if(strsrch(files[i],".oo.")>0)
            continue;
        file = dir+files[i];
        if(file_size(file)<=0)
            continue;
        user = new(USER_OB);
        if(!user || !objectp(user))
            continue;
        user->restore(file);
        if(member_array(user->query("id"),SECURITY_D->query_wizlist()) != -1)
        {
            destruct(user);
            continue;
        }
        if(user->query(arg1,1)==0)
        {
            destruct(user);
            continue;
        }
        printf(HIW"%s(%s) "+arg1+"="+user->query(arg1,1)+"\n"NOR,user->query("name"),user->query("id"));
        destruct(user);
    }
    if(head[0]<'z')
    {
        head[0]++;
        call_out("alluser_prop",0,arg1,arg2,head);
    }
    else
    {
        is_running=0;
        write(HIY"OK\n"NOR);
    }
}
