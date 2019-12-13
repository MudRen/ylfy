// cheng.c ��ҩ��

#include <ansi.h>
inherit NPC;

string do_zhuibu();
int get_reward(object me, object obj);

void create()
{
        set_name("��ҩ��", ({ "cheng yaofa", "cheng" }));
        set("title", "����֪��");
        set("gender", "����");
        set("age", 43);
        set("str", 40);
        set("dex", 20);
        set("long", "�����ǳ�ҩ������������֪����\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 15);

        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);

        set("inquiry", ([
                "׷��" : (: do_zhuibu :),
        ]));

        setup();
        carry_object("clone/weapon/gangjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

string do_zhuibu()
{

string *quest = ({
        //"��ˮ�ϰ�",
        "/d/nanyang/hanshui1",
        //"������",
        "/d/nanyang/nanyang",
        //"���ݳ�",
        "/d/nanyang/ruzhou",
        //"����ɽʯ��",
        "/d/nanyang/shijie2",
        //"��������",
        "/d/city2/xichang1",
        //"��������",
        "/d/city2/ximen",
        //"��ɽ�嶫���",
        "/d/village/eexit",
        //"��ɽ����ʯ·",
        "/d/village/eroad2",
        //"Ȫ�ݺ��ۿ�",
        "/d/quanzhou/haigang",
        //"Ȫ�ݱ���",
        "/d/quanzhou/beimen",
        //"����ɽ·",
        "/d/quanzhou/qzroad5",
        //"��������",
        "/d/quanzhou/jxnanmen",
        //"�����ϴ��",
        "/d/city/nandajie1",
        //"��ڷ�",
        "/d/taishan/daizong",
        //"̩ɽһ����",
        "/d/taishan/yitian",
        //"̩ɽʯ����",
        "/d/taishan/shijin",
        //"���Ǻ���",
        "/d/city2/haigang",
        //"��������ɽ",
        "/d/xingxiu/xxroad3",
        //"˿��֮·",
        "/d/xingxiu/silk1",
        //"�䵱����·",
        "/d/wudang/wdroad7",
        //"�䵱ɽ����",
        "/d/wudang/wdroad8",
        //"��ɽ����",
        "/d/xingxiu/shanjiao",
        //"����С��",
        "/d/xingxiu/beijiang",
        //"������",
        "/d/xingxiu/saimachang",
        //"��ɽ��Ů��",
        "/d/huashan/yunu",
        //"��ɽ������",
        "/d/huashan/zhenyue",
        //"��ɽ�����",
        "/d/huashan/husun",
        //"��ɽ���ƺ",
        "/d/huashan/qingke",
        //"��ɽ����",
        "/d/huashan/path1"
});

        object obj, ob = this_player();
        int exp = ob->query("combat_exp");

        if ( environment(this_object())->query("short")!="��������" )
                return "���ﲻ�����ţ������»�������˵�ɣ�";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

        if ( ob->query_condition("in_zhuibu") )
                return "�㲻�Ǽ�����׷������ ����㲻��ɣ��ͷ����ɡ�\n";


         if (exp < 100000000)
        {
                if (exp < 10000) {
                        command("pat " + ob->query("id"));
                        return ("��ҩ��˵��������ͻ�С�����˵�����ô�����أ�\n");
                }
                else if (exp < 100000) {
                        obj = new("/quest/quest2/thief");
                        obj->move(quest[random(28)]);
                        ob->set_temp("ץ/" + obj->query("id"), 1);
                }
                else if (exp < 200000) {
                        obj = new("/quest/quest2/zei");
                        obj->move(quest[random(28)]);
                        ob->set_temp("ץ/" + obj->query("id"), 1);
                }
                else if (exp < 300000) {
                        obj = new("/quest/quest2/dadao");
                        obj->move(quest[random(28)]);
                        ob->set_temp("ץ/" + obj->query("id"), 1);
                }
                else if (exp < 400000) {
                        obj = new("/quest/quest2/qinfan");
                        obj->move(quest[random(28)]);
                        ob->set_temp("ץ/" + obj->query("id"), 1);
                }
                  else if (exp < 100000000) {
                        obj = new("/quest/quest2/dawang");
                        obj->move(quest[random(28)]);
                        ob->set_temp("ץ/" + obj->query("id"), 1);
                }
                ob->start_busy(1);

                ob->set("oldtitle",ob->query("title"));
                ob->set("title",HIY"�������Ų���"NOR);
                ob->apply_condition("in_zhuibu", 20);
                message_vision(YEL"$N�ѱ�ί��Ϊ���Ų��졣\n"NOR,ob);
                remove_call_out("destrory");
                call_out("destrory",150,obj);
          return "��ȥ��" + obj->short() + "����ץ�����ɱ��������ˣ�\n";
        }
        else {
                return("��ҩ��˵��������С������������ݣ�\n");
        }
}

int accept_object(object me, object obj)
{
        if ( !me || environment(me) != environment() ) return 0;

        if ( !objectp(obj) ) return 0;

        if ( !present(obj, me) ) {say("��û�����������\n"); return 0;}

        if ( me->query_condition("in_zhuibu") ) {
                if ( me->query_temp("ץ/" + obj->query("id")) )
                {
                        command("nod");
                        command("say �ܺúܺã�������Ľ��͡�\n");
                        call_out("get_reward", 0, me, obj);
                        me->apply_condition("after_zhuibu", 7);
                        me->apply_condition("in_zhuibu", 0);
                        me->delete_temp("ץ/" + obj->query("id"));
                        me->set("title",me->query("oldtitle"));
                        me->delete("oldtitle");
                        return 1;
                }
                else {
                        command("heng");
                        command("say �����ĳ����������������Ҵ�\n");
                        message_vision("�������������ɲ��ӵ������Χס��һ��ʹ��......\n", me);
                        me->apply_condition("after_zhuibu", 7);
                        me->apply_condition("in_zhuibu", 0);
                        me->set("title",me->query("oldtitle"));
                        me->delete("oldtitle");
						me->move("/d/city/jianyu");
                        return 0;
                }
        }
        else {
                command("say �����ûʲô����ɣ�\n");
                return 0;
        }
}

int get_reward(object me, object obj)
{
        int exp, pot, bonus;
        int rand = random(3);
        if ( rand == 0 )
                rand = 1;

         exp =((int)me->query("literate"))+random(1500) + (int)random(me->query("combat_exp")/10000);
         pot = exp / 20;

                        remove_call_out("destrory");
                        call_out("destrory",1,obj);

        me->add("combat_exp", exp);
        bonus = (int)(me->query("potential")+pot);
        if( bonus > 210000)
        bonus = 210000;
        me->set("potential", bonus );
        tell_object(me, sprintf("��õ���%s��Ǳ�ܣ�%s�㾭�顣\n",chinese_number(pot),chinese_number(exp)));
}

void destrory(object ob)
{
        destruct(ob);
        return;
}
