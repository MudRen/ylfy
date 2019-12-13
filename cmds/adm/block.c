// function:    block player to /clone/misc/block.c
// creator:     ken@xajh.chinesemud.net
// creat time:  1998/04/27
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
inherit F_DBASE;
 
void auto_post(string title,string arg);
 
void create() 
{
        seteuid(getuid());
        set("channel_id","��Ϸ����(block)");
}
 
int main(object me, string arg)
{
        object ob;
        int day;
        string who,why;
 
        if (!arg) return notify_fail("<Syntax>: block <player id> <day> because <why>.\n");

        if( sscanf(arg,"%s %d because %s",who,day,why) != 3 )
                return notify_fail("<Syntax>: block <player id> <day> because <why>.\n");

        if( day < 1 || day > 100 )
                return notify_fail("block player must up to 1~100 day.\n");

        ob = LOGIN_D->find_body(who);
        if (!ob) return notify_fail("No suck player online now ...\n");

        // moving

        if( wiz_level(me) < wiz_level("(arch)") && wizardp(ob) )
                return notify_fail("OOp���㲻�� block ��ʦ��\n");

        if ( ob->query("block") )
                        return notify_fail(
sprintf("%s(%s)������Ҽ������� %s �ͷţ���ʱ����˵�ɡ�\n",	
                                        ob->name(),ob->query("id"),
                                        ctime((int)ob->query("block/time")) )
                                );
        tell_object(ob,RED"\n\nһ�������, ����ǰһ���....\n\n"NOR);

        ob->set("block/time",time()+day*24*60*60);
        ob->move("/clone/misc/block");

tell_object(me, "���"+(string)ob->query("name")+"�ؽ�����Ҽ���.\n");	

        tell_object(ob,YEL"\n.... ����ʱ������"+(string)me->query("name")+
"����ؽ�����Ҽ���.\n\n"NOR);	

        auto_post(
sprintf("���棺%s���ؽ�����Ҽ���.",ob->name() ),	

                sprintf("%s(%s) ��Ϊ %s ��Ե�ʣ�\n"
"���ڽ��������Ҽ��� %d �죬���� %s ���Զ��ͷš�\n\n",	
                        ob->name(),ob->query("id"),why,
                        day,ctime((int)ob->query("block/time"))
        ) );

        if( !wizardp(ob) )
CHANNEL_D->do_channel(this_object(),"xyxw",ob->query("name")+"���ؽ�����Ҽ�����");                     	
        // ok ..
        return 1;
}

void auto_post(string title,string body) {
        mapping note;
        object POSTER;
        if( objectp(POSTER=load_object("/clone/board/towiz_b")) )
        {
                note=([]);
                note["title"] = title;;
                note["author"] = sprintf("%s(%s)",this_player()->query("name"),this_player()->query("id"));
                note["time"] = time();
                POSTER->done_post(this_player(),note,body);
        }
        return;
}

int help(object me)
{
write(@HELP
ָ���ʽ : block <ĳ��> <����> because <ԭ��>

��ָ�������(��)��ĳ�˹ص���Ҽ�����	
HELP
    );
    return 1;
}
