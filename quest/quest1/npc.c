#include <ansi.h>
#define QUEST_SHA "/quest/quest1/quest"
inherit NPC;
inherit F_MASTER;
int time_period(int timep, object me);

void create()
{
        set_name("�Ų�",({"postman"}));
        set("long",
                "����һ��������Ų��������ż���Χ�ţ���������ü���������ӡ�\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 20);
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 30000000);
        set("score", 10000);
        set("env/wimpy", 10000);
        set("inquiry", ([
                "����": "�����ڷ�����ô������Щ�ż�������������! \n",
        ]) );
        set("no_get", 1);
/*
        set("chat_msg", ({
                (: random_move :)
        }) );
*/
        set_skill("force", 170);
        set_skill("dodge", 170);
//         set_skill("cuff", 175)
        set_skill("parry", 170);
        setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");

}


int give_quest()
{
        mapping quest ;
        object me,letter;
        int combatexp, timep, factor;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

if(combatexp > 150000000)
        {
                message_vision("�Ų��$N˵�����������ָ����ˣ�����С������������ݣ���\n",me);
                return 0;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("�Ų��$N˵�� ��ð��Ű����͵�ѽ��\n", me);
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("�Ų��$N˵���������Ҷ��е÷��ţ��㻹�ǵȻ������ɡ�\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("�Ų��$N˵�����������ã�������պ���һ���ż�Ҫ�ͳ�ȥ��\n",me);
}
        quest = QUEST_SHA->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);

        tell_object(me, "�����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        letter = new("/quest/quest1/letter");
        letter->move(me);
        quest["quest_type"] = "�����͸�";
        quest["exp_bonus"] = random(200) + 50;
        quest["pot_bonus"] = random(20) + 20;
        quest["score"] = random(10)+8;

        me->set("quest", quest);
        me->set("task_time", (int)time() + timep);
        me->set("quest_factor", factor);
        me->set("last_task_time", time());
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "��";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me, HIW "�Ų�˵����\n��" + time + "��");

                return 1;
}

