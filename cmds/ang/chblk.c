// channel block command..

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        
    if (!arg)
        return  notify_fail("�����ʽ: chblk <���id>\n");
    
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("����˲��ڣ�\n");
//if (wizardp(ob)) return notify_fail("���ܹر���ʦ��Ƶ����\n");
        if (time()- ob->query("chblk_channel")<3600)
                tell_object(me,(string)ob->query("name")+"������Ƶ���ǹرյġ�\n");
        else{
                ob->set("chblk_channel",time());
                tell_object(me, (string)ob->query("name")+"������Ƶ�����ر��ˡ�\n");
        }
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : chblk <ĳ��>

       ������ر�ĳ�˵�Ƶ����
HELP
    );
    return 1;
}

