// channel unblock command..

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        
    if (!arg)
        return  notify_fail("�����ʽ: unchblk <���id>\n");
    
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("����˲��ڣ�\n");
        if (time()- ob->query("chblk_channel")>3600)
                tell_object(me,(string)ob->query("name")+"������Ƶ���Ǵ򿪵ġ�\n");
        else{
                ob->delete("chblk_channel");
                tell_object(me, (string)ob->query("name")+"������Ƶ�������ˡ�\n");
        }
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : unchblk <ĳ��>

       �������ĳ�˵Ľ�̸Ƶ����
HELP
    );
    return 1;
}

