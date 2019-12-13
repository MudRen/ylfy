#include <ansi.h>
// fang.c 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"ʯ��"NOR);
        set("long",@long
һ��յ�����ʯ�ң���ǰ������һ����̳������ʷ���һЩ�Ϲ���������
��ɢ����ҡҷ�Ļ�⣬һЩ��Ĺ���������ַ���Ĺ��������׼��ʷ��ڼ�̳��
��������ο�����Ӣ�顣
long);

        set("exits",([
        "north" : __DIR__"gmqs",
        "south" : __DIR__"gmcc",
        "east" : __DIR__"yaofang",
        ]));

        setup();
}

void init()
{
     add_action("do_jibai","jibai");
     add_action("do_ketou","ketou"); 
}

int do_jibai(string arg)
{
        object me,ob;
        int exp,pot,score;
        me=this_player();       
        ob = present("head", me);
        if ( arg == "head") {
        if ( ! ob )
              return notify_fail("��û����ͷ������ʲô��\n");        
        if ( !me->query_temp("gm/job")) 
              return notify_fail("�㻹ûȥѲ���أ�����������׼���\n");
        if(ob->query("name") != "����Ů�ӵ��׼�")
              return notify_fail("������Ū������ͷ�����˺����ǹ�Ĺ���氡��\n");        
        if( ob->query("victim_user")) 
              return notify_fail("������Ū�����׼���ɱ�����˰ɣ�\n");
//        if( ob->query("kill_by") != me)
//              return notify_fail("���������ɱ�İɣ�������ô�õ������ͷ�ģ�\n");
        message_vision(HIY"$N���������ؿ��˼�����ͷ��Ȼ��������$n�ʷ��ڼ�̳���ࡣ\n"NOR,me,ob);
        exp =30+random(20);
        me->add("combat_exp",exp);
        pot= 20+random(10);
        me->add("potential",pot);
        score= 5+random(5);
        me->add("score",score);
        me->delete_temp("gm/job");        
        me->delete_temp("meet_nuzi");        
        call_out("destroying", 1, ob);
        tell_object(me,HIW"�㱻�����ˣ�\n" + 
        chinese_number(exp) + "��ʵս����\n" +
        chinese_number(pot) + "��Ǳ��\n" +
        chinese_number(score) + "��ʦ���ҳ϶�\n"NOR);        
        return 1;       
        }
      return notify_fail("����ʲô���ݰ���\n");
}

void destroying(object ob)
{
        destruct(ob);
        return;
}

int do_ketou(string arg)
{
        mapping fam;
        object me=this_player();
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ��ڴ˿�ͷ������\n");
        if ( arg == "jitan"){
        if ( me->query("combat_exp")<30000)
           return notify_fail("�㿴�ż�̳���ĸ�����̫����ɻֲ̿�����������վ������\n");
        if ( me->query("combat_exp") > 180000)
           return notify_fail("�㻹��ȥ�����϶��Щ������ο��ʦ�ɣ�\n");
        if ( me->query_temp("bishou") < 2 ){
          if(objectp(present("bi shou", me)))        
           return notify_fail("�㷢�ֺ������Ѿ��յ����ģ�ʲôҲû���ˡ�\n");   
          me->add_temp("bishou", 1);
          message_vision(HIY"$N���������ض��ż�̳����ͷ����\n"NOR, me);
          return 1;
          }                      
          message_vision(YEL"��̳����ת����$N�������С�������ó�һ��ذ�ס�\n"NOR, me);
          me->delete_temp("bishou");
          new(__DIR__"obj/bishou")->move(me);
          return 1;
          }
     return notify_fail("�����ʲô��ͷ����\n");
}


int do_tiao(string arg)
{
        object me;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "shenyuan")
                return notify_fail("��Ҫ��������\n");
        if( !me->query_temp("tiaoya") )
        {
                write(HIR"�������������գ������ô����ȥֻ���׶༪�٣��㻹���ٿ���һ�°ɡ�\n"NOR);
                write(HIR"���������ã�yes�����ı�������ã�no����\n"NOR);
                me->set_temp("tiaoya", 1);
                return 1;
        }
        write("�㵽����ô�����ģ�\n");
        return 1;
}

int do_yes()
{
        object me;
        me= this_player();
        //int j;
        //j=(int)me->query("kar", 1);
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if( !me->query_temp("tiaoya") )
                return 0;
        message_vision(HIR"$N��ԥ�����������¶����ģ�����һ�գ�ӿ�����µ���ȥ��\n"NOR, me);
        //write("����ԥ�����������¶����ģ�����һ�գ�ӿ�����µ���ȥ��\n");
        me->delete_temp("tiaoya");
        message_vision(HIR"\n$N����忪����ֻ�о��������磬���µ�ֱ׹��ȥ��\n"NOR,me);
        if ((int)me->query("kar",1) >=28)
        //if (random(25) >= 1)
        {
                call_out("win", 1);
                return 1;
        }       
        //write("���������ȵ�Խ��Խ����������ȥ���ȵ�ԭ����һƬˮ̶��\n",);
        call_out("fail", 1);
        return 1;       
        
}

int do_no()
{
        object me;
        me=this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if( !me->query_temp("tiaoya") )
                return 0;
        write(HIG"��˼������ȡ��������ȥ�ľ�����\n"NOR);
        me->delete_temp("tiaoya");
        return 1;
}

int win()
{
        object me;
        me=this_player();
        write(HIR"\n���������ȵ�Խ��Խ����������ȥ���ȵ�ԭ����һƬˮ̶��\n"NOR,);
        write(HIR"\n���ڿ��У������Ѿ����ܿ��ƣ�ֱ����ˮ����ȥ��\n"NOR);
        write(HIR"\n��ͨһ���������������ˮ����������һ�󷭹���������Ҫ���������๾�࣬
����������һ����ˮ��\n"NOR);
       me->move(__DIR__"guditan1");
       tell_room(environment(me), "ֻ����һ���ҽУ�"+me->name() + "�����ֱ׹��������\n", ({ me }));
       tell_room(environment(me), me->name() + "�����澶ֱ������ȥ��\n", ({ me }));
       me->receive_damage("jingli", 100);
       me->receive_damage("qi", 100);
       me->move(__DIR__"guditan2");
       tell_room(environment(me), me->name() + "������ֱ׹��������\n", ({ me }));
       tell_room(environment(me), me->name() + "�����澶ֱ������ȥ��\n", ({ me }));
       me->receive_damage("jingli", 200);
       me->receive_damage("qi", 200);
       me->move(__DIR__"guditan3");
       tell_room(environment(me), me->name() + "������ֱ׹��������\n", ({ me }));
       tell_room(environment(me), me->name() + "�����澶ֱ������ȥ��\n", ({ me }));
       me->receive_damage("jingli", 300);
       me->receive_damage("qi", 300);
       me->set("water", me->max_water_capacity()+200);
       me->move(__DIR__"guditan4");       
       tell_room(environment(me), me->name() + "������ֱ׹��������\n", ({ me }));
       message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
       return 1;
        
}

int fail()
{
        object me, tmp;
        object *ob;
        int i;
        me= this_player();
        write(HIR"\n���������ȵ�Խ��Խ����������ȥ���ȵ�ԭ����һƬˮ̶��\n"NOR,);
        write(HIR"\n���ڿ��У������Ѿ����ܿ��ƣ�ֱ����̶��һ���ʯͷ׹ȥ��\n"NOR, );
        write(HIR"\n�㼱ת���Σ���Ҫ�������������������ڿ��У�Ʈ�����Ļ벻�������ۿ���
����ʯͷԽ��Խ���ˣ���ʱ�������в�������һ˿���⣺С��Ů�����ֲ����ң�
����������ʲô��\n"NOR);
       me->move(__DIR__"gudi");
       me->set_temp("last_damage_from","����ɽ��ˤ");
       me->unconcious();
       me->die();
        if (tmp = present("corpse", this_object())) 
        {
                ob = deep_inventory(tmp);
                i = sizeof(ob);
                while (i--) if (userp(ob[i])) ob[i]->move(this_object());
                destruct(tmp);
               destruct("corpse");
               if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
        }
        return 1;
}

