//wiz_apply

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HBRED "������ʦ��"NOR);
        set("long", @LONG
[1;35m ���ȣ�����뿼���������Ϊһ����ʦ�����㽫Ը�⻨����ռȥ���
���ֵ�����ʱ��������ϣ�����㲻Ը�⣬��û��ǵ�����ҵĺã�����
Ŀǰ��Ҫ�����������ʦ����ͬ���������mud���ǵ���Ҫ
        1. ������Ǹ��������������.
        2. �����ѧ�� C ���� �� LPC ���ԡ�
        3. ������С˵��һ������ʶ��
        4. ������к����˺������������������ͱ����޸������Ʒ��������

   ���ǲ������������ʦ�κ�ѹ���������¶�����Ҫ��Ϊһ����ʦ֮�ᣬ
������Ϊ�Լ��ܹ�����������,

                ���������ġ���ʵ��������
                ���������ġ���ʦ��������
                ����������ʦ�ġ�Ӣ����������
                ���������ġ��Ա𡽣�
                ���������ġ����䡽��
                ���������ġ�e-mail��ַ����

                �����ϵ��ַ�͵绰��������
                ��ĵ�λ��ѧУ����
                ���Ƿ����㹻��ʱ�������뱾MUD�Ľ��裺
                �Ƿ���Ϥmud��
                ����Ϥ�Ǽ��ֳ������ԣ��磺C,C++,JAVA,LPC ��

     [0;5;1;37m        ������return��������뿪����!

LONG);
        set("exits",([]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
        call_other("/clone/board/wizapply_b", "???");
}

void init()
{
        add_action("do_return", "return");
        add_action("do_wizapply","wizapply");
}

int do_return(string arg)
{
        object me = this_player();

        message_vision(HIC"ֻ����ǰһ��"HIR"���\n"NOR,me);
        message_vision(HIR"�ռ�һ��ת�䣬$N�����ͻ����ĵط���\n"NOR,me);

        if (me->query("old_place"))     me->move(me->query("old_place"));
        else me->move("/d/city/wumiao");
        message_vision(HIR"�ռ�һ��ת�䣬$N�����͵�����һ�����ȡ�\n"NOR,me);
        me->delete("old_place");
        return 1;
}

int do_wizapply(string arg)
{
        write("���Ѿ�������Ͳ�������wizapply�ˡ�\n");
        return 1;
}
