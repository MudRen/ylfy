// danuoyi.c

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
        set_name(HIG"Ǭ����Ų���ķ�"NOR, ({ "danuoyi xinfa" ,"xinfa"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ����Ƥֽ��������һЩ��µ��־䣬�ƺ�\n"
                        "�ᵽһЩ�˹�����Ϣ����ʲ��ġ�\n");
                set("value", 6000);
                set("material", "paper");
                set("no_give", "�����������ܸ����ˡ�\n");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_sell", "����������������\n");
                  set("no_steal",1);
                  set("no_put",1);
                set("skill", ([
                        "name":                 "qiankundanuoyi",          
                        "exp_required": 200000,                        

                        "jing_cost":             80,                          
  
                        "difficulty":   60,                             
                                                
                ]) );
        }
}

int do_du(string arg)
{
        object me = this_player();      
        int qklevel; 

        if (!(arg=="danuoyi xinfa" || arg == "xinfa" || arg == "book"))
        return 0;

        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (!id(arg)) { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if ((string)me->query("gender") == "Ů��" ){
                write("�Թ�û��Ů�˿�����Ǭ����Ų�Ƶġ�\n");
                return 1;
        }

        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "��ɫ������죬�仯�޶ˡ�\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "��ɫ����������棬���첻�ѡ�\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "ͷ��ð��һ�����̣��þò�ɢ��\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        qklevel = me->query_skill("danuoyi", 1);
        if( (int)me->query("combat_exp") < (int)qklevel*qklevel*qklevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
if( me->query_skill("jiuyang-shengong", 1) < 150 && me->query_skill("jiuyang-shengong", 1) < 150){	
                write("Ǭ����Ų�Ʊ����Ͼ����񹦣�\n");
                return 1;
        }

        if( me->query("combat_exp") < 200000){
                write("Ǭ����Ų����Ҫ���������������㻹̫�\n");
                return 1;
        }

        if( me->query_skill("qiankundanuoyi", 1) > 250){
                write("���Ѿ���Ǭ����Ų���޵��ھŲ��ˣ����Ѿ�û��ʲô����Ҫ֤�����ˣ�\n");
                return 1;
        }

        me->receive_damage("jing", 80);
        if( !me->query_skill("qiankundanuoyi", 1) ) {
                me->set_skill("qiankundanuoyi", 0);
write("\n");
        }
        me->improve_skill("qiankundanuoyi", (int)me->query_skill("literate", 1)/10+1);
        write("���ж�Ǭ����Ų���ķ��������ĵá�\n");
        return 1;
}
int query_autoload() { return 1; }
