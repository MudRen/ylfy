// mihan.c


inherit ITEM;

void create()
{
        set_name( "����", ({ "biao yin", "biao","yin" }) );
        set_weight(2000+random(3000));
        set("no_put", 1);                       // �����������ܷ�������
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ھ��и������������\n");
        }
}

void init()
{
        add_action("do_give", "give");

        remove_call_out("attract_robber");
        call_out("attract_robber", 1);

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 4, query("target"));
                delete("target");               // add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}

int do_give(string arg)
{
        object me,ob,home;
        string obj,target;
        int i;
       if(!arg || arg==" ")
            return 0;
        if (sscanf(arg,"%s to %s", obj, target)!=2 )
                if(sscanf(arg,"%s %s", target, obj) !=2 )       
                        return 0;

        if(!id(obj) )   return 0;

        me = this_player();

        if(!ob = present(target,environment(me)) ) {
                tell_object(me,"����Ҫ����������˭��\n");
                return 1;
        }
        if(!ob->id(query("target")) || userp(ob)) {
                tell_object(me, "�㲻�ܰ���������������ˡ�\n");
                return 1;
        }
        if(!living(ob) ) {
                tell_object(me,ob->query("name")+"�Ѿ��޷��������������ˡ�\n");
                return 1;
        }

        if(!home = find_object(ob->query("startroom")) )
                home = load_object(ob->query("startroom"));
    if (environment(ob)!=home){
                message_vision(CYN+"$N˵������������æ���أ����һ�ȥ��˵�ɣ�"+NOR,ob);
        return 1;
    }
        message_vision("$N�ó�һ������������" + ob->query("name") + "��\n", me);
        if((time()-me->query( "biao_start" ))>me->query( "biao_time" ) ) {
                message_vision(CYN+"$N�������ض�$n˵������ô����¶��첻�ã���û�ã�\n"+NOR, ob, me);
                tell_object(me, "��û�м�ʱ�������͵�" + ob->query("name") + "�����У��������ʧ���ˣ�\n");
                me->set("biao_failed", 1);
        }
        else {
                message_vision(CYN+"$N��$nЦ�����ܺã�����һ�ɵĺ���������ȥ�ɣ�\n"+NOR, ob, me);
                tell_object(me, "��ɹ��ؽ������͵���" + ob->query("name") + "�����С�\n");
                i = 200 + random(me->query( "biao_time" )-time()+me->query( "biao_start" ))/5;
                tell_object(me, sprintf(WHT"������%s��ս�����飡\n"NOR, chinese_number(i)) );
                me->add("combat_exp", 10*i);
                me->add("potential",i/10+1);
                tell_object(me, sprintf(WHT"%s��Ǳ��\n"NOR, chinese_number(i/20+1)) );
                        ob=new(SILVER_OB);
                        if (!ob->move(me))
                                        ob->move(environment(me));
                        ob->add_amount(random(50)+30);
                me->delete("biao_start");
                me->delete("biao_time");
        }

        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);

        destruct(this_object());

        return 1;
}

// ����ǿ��
void attract_robber()
{
        object ob, robber, room;

        if(!userp(ob = environment(this_object())) ) return;
        if (time()-ob->query( "biao_start" )>ob->query( "biao_time" )+300 ){
            destruct(this_object());
            return;
        }
        room = environment(ob);

        if(room->query("outdoors") && !present("mask robber",room) ) {
            robber = new("/d/npc/robber");
            robber->move(room);
            message_vision("$N���˹�����\n",robber);
        }

        remove_call_out("attract_robber");
        call_out("attract_robber", 1);
}
void owner_is_killed() { destruct(this_object()); }

