// post_officer.c

inherit NPC;
string send_mail();
string receive_mail();
void create()
{
        set_name("�ſ�", ({ "post officer", "post","officer" }) );
        set("title", "�䳤");
        set("gender", "����" );
        set("age", 43);
        set("long",
                "�ſ���ѩͤ����䳤�Ѿ���ʮ�����ˣ���Ȼ�ڼ��м�����Ǩ��\n"
                "���ᣬ����������Ϊ�᲻���뿪�������ˣ����Ӧ���ӵ����룬\n"
                "�����߳�ES2���������ﵱ��վվ�������Ӷ������Ǹм���\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "��������ѽ�����������ʼ����ң����սп����죬��\n�������������վվ����������һ������ʦӴ��",
                "��վ" : "�ǰ�... ������������䣬��Ҫ������",
                "����" : (: send_mail :),
                "����" : (: receive_mail :),
                "mail" : (: receive_mail :),
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 50);
        set_skill("unarmed", 40);
        setup();
        add_money("coin", 70);
}
string send_mail()
{
        object mbox;
        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}
string receive_mail()
{
        object mbox;
        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ������е��Ŷ������档\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}
void init()
{
    if( !environment()  ||  base_name(environment()) != query("startroom") )
            return;
    add_action("give_quest", "quest");

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

        tell_object(me, HIW "�ſ�˵������" + time + "��");

                return 1;
}



int give_quest()
{
        object me,letter;
        object *ob=livings();
        int i,timep;

        me = this_player();

        if((int)(me->query("combat_exp")) > 150000000){
                message_vision("�ſ��$N˵�����������־��������ˣ�����С������������ݣ���\n",me);
                return 0;
        }
        
        if( ((int)me->query("letter/task_time")) >  time() ){
                tell_object(me,"�����ڵ������ǰ����͸�"+me->query("letter/target")+"\n");
                message_vision("�ſ������Ķ�$N˵�� ��ð��Ű����͵�ѽ��\n", me);
                return 0;
        }
        message_vision("�ſ��$N˵�����������ã�������պ���һ���ż�Ҫ�ͳ�ȥ��\n",me);
        timep = random(100) + 300;
        i=random(sizeof(ob));
        while (1){
                i++;
                if (i==sizeof(ob))
                    i=random(sizeof(ob));
                if (ob[i]==me)  continue;
                if (!environment(ob[i])) continue;
                if (ob[i]->is_ghost())  continue;
                if (random(20)==3)
                    if ( !userp(ob[i]) ) continue;
                if (sscanf(base_name(ob[i]),"/u/%*s" )) continue;
         break;
        }
        time_period(timep,me);
        tell_object(me, "�����͸���" + ob[i]->short() + HIW +"��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        letter = new("d/city/obj/letter");
        letter->set_target(ob[i]->short());
        letter->move(me);
        me->set("letter/target",ob[i]->short());
        me->set("letter/task_time", (int)time() + timep);
        return 1;
}

