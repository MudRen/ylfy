// fengchao.c by river 98/08/29
#include <ansi.h>
inherit ROOM;

void delete_hexiu(object me, object arg);

void create()
{
          set("short",HIR"�䳲"NOR);
          set("long", @LONG
��Ժ컨�ſ����������ɣ����ܲ�㣬�����˱ǣ�������������һ������
�磬�����֦��ɷ�Ǻÿ������������񴹸ǣ�������Ȼ��ɵ�һ���������ݡ�
���ܶ���һƬ���ģ�ֻ��Ȫ����������˼���ȷ�Ǹ��Ϻõ��������ڡ�
LONG        );

          set("exits", ([
               "eastdown" : __DIR__"guoyuan",
          ]));

          set("outdoors","��Ĺ");          

          setup();
}

void init()
{
       add_action("do_tong","tong");
}

int do_tong(string arg)
{
        object me = this_player();        
        mapping fam;        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
            return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˣ���Ҫ���ڹ�Ĺ�����ˡ�\n");
        if ( arg =="fengchao"){
           if ( me->query_condition("gumu_job" ) > 0 )
                return notify_fail("��ͱ�˰��췢�ַ䳲��ʲô��û���ˡ�\n");
           if ( me->query("combat_exp") < 30000)
                return notify_fail("�ɷ��ۺ�Σ�գ������ڻ����ܸɡ�\n");
           if (me->query("combat_exp") > 120000 )
                return notify_fail("���书�Ѿ����ߣ��ɷ��۵��¾���С������ȥ���ɡ�\n");
           if ( me->query_temp("gm_fengmi"))
                return notify_fail("�㲻���Ѿ����˷�����ô��\n");
           message_vision(HIY"$N����ͱ��ͱ�䳲�������ڳ��˲��ٷ��ۡ�\n"NOR,me);
           new(__DIR__"obj/fengmi")->move(me);
           me->start_busy(5);
           call_out("danger", 3, me);
           return 1;
           }
        return notify_fail("�����ͱ�˼��£����ʲôҲû�з�����\n");
}

void danger(object me)
{
          object obj;
          tell_object(me, HIR"����Լ�о����ж���Χ�˹���....�������Ĺۣ������Լ�����Χ�ˡ�\n" NOR);
          new(__DIR__"/npc/beast")->move(__DIR__"fengchao");                       
          obj = present("feng mi", me);
          destruct(obj);
          tell_object(me, RED "����������������������ڵ��ϡ�\n" NOR);
          me->set_temp("gm_fengmi",1);
}

