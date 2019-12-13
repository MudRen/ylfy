inherit ITEM;

void create()
{
        set_name("�ż�", ({"xin", "letter"}));
        set("weight", 5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�����Ų��и�����ż���\n");
                set("unit", "��");
                set("no_get", 1);
        }
        setup();
}



void init()
{
        add_action("do_give", "give");

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 6, query("target"));
                delete("target");               // add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}

int do_give(string arg)
{
        object me,ob;
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
                tell_object(me,"����Ҫ���Ž���˭��\n");
                return 1;
        }
        if( ob->short() != query("target")) {
                tell_object(me, "�㲻�ܰ��Ž�������ˡ�\n");
                return 1;
        }
        if(!living(ob) ) {
                tell_object(me,ob->query("name")+"�Ѿ��޷��������������ˡ�\n");
                return 1;
        }

        message("vision",me->name()+"�ó�һ���Ž�����" + ob->name() + "��\n", environment(me),({ me, ob }));
        if((time() > me->query( "letter/task_time" )) ) {
                tell_object(me,ob->name()+"�����ſ��˿��������ص�����һ�ۡ�\n");
                tell_object(me, "��û�м�ʱ�����͵�" + ob->query("name") + "�����У��������ʧ���ˣ�\n");
        } else {
                tell_object(me,ob->name()+"˵������л����л��\n");
                tell_object(me, "��ɹ��ذ����͵���" + ob->name() + "�����С�\n");
                i = random(80)+( me->query("letter/task_time")-time())/3;
                tell_object(me, sprintf(WHT"������%s��ս�����飡\n"NOR, chinese_number(i)) );
                me->add("combat_exp", i);
                me->add("potential",i/20+1);
                tell_object(me, sprintf(WHT"%s��Ǳ��\n"NOR, chinese_number(i/20+1)) );
                ob=new(SILVER_OB);
                if (!ob->move(me))
                      ob->move(environment(me));
                      ob->add_amount(random(50)+30);
                me->delete("letter");
        }
        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);
        destruct(this_object());
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

int query_autoload() { return 1; }