#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIW"�ɺ�"NOR, ({ "xian he", "he" }) );
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һֻ���������ɺף������������(qi)��ȥ.\n");
        set("attitude", "peaceful");
//        set("spi",100);
        set("int",100);
        set("per",100);
        set("con",100);
        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 900000000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 0);
        set_temp("apply/defence",90);

        setup();
}
void die()
{
        object ob,me;
me = this_player();
        message_vision("$N˻�ƵĽ��˼��������ڵ������ˡ�����\n һ���׹�������һ����������ëƮ����$N�����ϡ���\n\n", this_object(),me);
        ob = new("/d/hainan/obj/yumao");
        ob->move(me);
        destruct(this_object());
}
void init()
{
        add_action("do_xia","xia");
        add_action("do_qi","qi");
        add_action("do_qu","qu");
}
int do_qi(string arg)
{
        object me;
        int extra;
        me = this_player();
        if (arg = "�ɺ�" && arg = "xian he" && arg = "he")
        {
                extra = me->query_skill("jiaheshu",1);
                if (extra < 100) return notify_fail("��ļݺ���������������\n");
                if (me->query_temp("mark/qi1")) return notify_fail("�㻹Ҫ�ﵽ�ɺ��Դ���ȥ��\n");
                message_vision(HIW"ֻ��$N����Ծ�����ɺ׵ĺ󱳣��ɺ�����$N��������ա�����\n\n\n"NOR,me);
                set("long","һֻ���������ɺף��и���������������.\n");
                me->set_temp("mark/qi1",1);
                me->set_temp("mark/tiankong",1);
                me->move("/d/hainan/kongzhong");
                this_object()->move("/d/hainan/kongzhong");
                return 1;
        }
}

int do_xia(string arg)
{
        object me;
        me = this_player();
        if (arg != "�ɺ�" && arg != "xian he" && arg != "he") 
                return notify_fail("��Ҫ����ȥ��\n");
        if (!me->query_temp("mark/qi1")) return notify_fail("��Ҫ���ģ�������\n");
        if (me->query_temp("mark/tiankong"))
        {
                message_vision(HIR"$N�������ɺף������Ŵӿ��е�����ȥ��.....\n\n\n"NOR,me);
                me->die();
                message("rumor",YEL"��ҥ�ԡ�ĳ�ˣ��������ѣ�����һ�ˣ�\n"NOR,users());
                destruct(this_object());
        }
        else
        {
                message_vision("ֻ��$N����һԾ���������ɺס�\n",me);
                set("long","һֻ���������ɺף������������(qi)��ȥ.\n");
                me->delete_temp("mark/qi1",);
        }
        return 1;
}
int do_qu(string arg)
{
        object me;
        string gg;
        me = this_player();
        if((int)me->query("combat_exp") <1500000)
        {
                return notify_fail("��ľ��鲻�������޷������ɺס�\n");
                message_vision(HIW"ֻ��$N���ɺ���ҡҡ���䣬��Ҫ�������ˡ�����\n\n\n\n�ɺ���������������������������\n"NOR,me);
        }
        if(! arg )
                return notify_fail("��׼�������ɺ׵����\n\n�����ȥ�ĵط��У�\n����(yangzhou)    �ɶ�(chengdu)    ����ɽ(baituo)    ����(dali)\n����(beijing)    ��ɽ(huashan)     ����(kunlun)    �㵴(yandang)    ����(emei)\n���չ�(lingjiu)   Ȫ��(quanzhou)      ����(kaifeng)      �䵱(wudang)\n");
        if(arg=="yangzhou")     
                gg=("/d/city/guangchang");
        else if(arg=="chengdu") 
                gg=("/d/city3/guangchang");
        else if(arg=="baituoshan") 
                gg=("/d/baituo/dating");
        else if(arg=="dali") 
                gg=("/d/dali/guangchang");
        else if(arg=="beijing") 
                gg=("/d/city2/tian_anm");
        else if(arg=="huashan") 
                gg=("/d/huashan/square");
        else if(arg=="kunlun") 
                gg=("/d/gaochang/room63");
        else if(arg=="yandang") 
                gg=("/d/yandang/jiedao");
        else if(arg=="emei") 
                gg=("/d/emei/guangchang");
        else if(arg=="kaifeng") 
                gg=("/d/kaifeng/eastx");
        else if(arg=="lingjiu") 
                gg=("/d/lingjiu/damen");
        else if(arg=="quanzhou") 
                gg=("/d/quanzhou/zhongxin");
        else if(arg=="wudang") 
                gg=("/d/wudang/sanqingdian");
        else    {
                return notify_fail("���޷������ɺ׵�����!\n");
        }
        message_vision("ֻ�����д���һ����˻,һֻ�׺���������.\n",me);
        me->move(gg);
        me->delete_temp("mark/tiankong");
        me->delete_temp("mark/qi1");
        message_vision("ֻ��$N��������һ������ϵ�����������\n",me);
        this_object()->move(gg);
        message_vision(HIW"$N���ݵ��ɺ׽��˼����󣬷����ˡ�������\n\n\n"NOR,me);
        destruct(this_object());
        return 1;
}
