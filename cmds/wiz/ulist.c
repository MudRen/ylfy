// user list
inherit F_CLEAN_UP;
int main(string str)
{
    foreach(object player in users()){
        write(sprintf("%15s : %30s\n",player->query("id"),
        file_name(player)));
    }
    return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : ulist
������������ҵ�/obj/user number ��ʾ������
HELP
    );
    return 1;
}

