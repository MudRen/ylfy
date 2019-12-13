// shiguan.c By csy

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIB"ʯ����"NOR);
    set("long", @LONG
�׸��ڲ��ƺ�д�����֣���Ŀ��ȥ��������ʮ�������֣�����Ů�ľ�����
ѹȫ�档����һ����������ˡ�����ʮ��������Ũī���飬�����Ծ���������
����ʱ�׸�ֻ�ƿ���һ�룬��б�ۿ�ȥ���������������
LONG
        );

    set("exits", ([ 
            "out"  : __DIR__"lingshi",
    ]));
   
    set("no_fight",1);    
    setup();
}

void init()
{
        add_action("do_dian", "use");
        add_action("do_turn", "turn");
        add_action("do_turn", "zhuan");
        add_action("do_ti", "ti");        
        add_action("do_search","search");
		add_action("do_canwu", "canwu");
}

int do_dian(string arg)
{
        object ob,me=this_player();         
        if ( arg == "fire"){
         if(!objectp(ob = present("fire", me)))        
           return notify_fail("��û�л��ۣ���ʲô��\n");
          message_vision(HIR"ֻ�������� ---����һ����$N���������еĻ��ۡ�\n\n"NOR,me);
          write(HIY"�ٿ���ʮ������ʱ��ֻ�����д�������С�֣��ƽ���Ů�ľ�֮��������
֮�ڴ���֮�£�������Ե��һ�۱�֪ ......�������� .....\n"NOR);
          me->set_temp("marks/��Ĺ1", 1);
          return 1;
          }
       return 0;
}

int do_search()
{
         object me = this_player();
         if (!me->query_temp("marks/��Ĺ1"))
           return 0;
         if (me->query_temp("gumu1") < 8){
           message_vision(HIY"$N�������ۣ���ϸ����ʯ��������������\n"NOR,me);
           me->add_temp("gumu1",1);
           return 1;
           }
           message_vision(HIR"$N��������һ������Ȼ����������һ�ֵİ�(ao)����\n"NOR,me);
           me->delete_temp("marks/��Ĺ1");
           me->delete_temp("gumu1");
           me->set_temp("marks/��Ĺ2", 1);
        return 1;
}
           
int do_turn(string arg)
{
         object me=this_player();
         string dir;               
         if (!me->query_temp("marks/��Ĺ2"))
           return 0;
         if (!arg||arg=="") return 0;
         if (me->is_busy() || me->is_fighting())
           return notify_fail("����æ���ģ�\n");    
         if( arg=="ao" ) {
           write("��Ҫ�Ѱ���������ת��\n");
           }
        if( sscanf(arg, "ao %s", dir)==1 ) {
           if( dir=="left") {
           message_vision(HIG"$N����������ת�����£���Ȼ��Щ�ɶ���\n"NOR,me );
           me->delete_temp("marks/��Ĺ2");
           me->set_temp("marks/��Ĺ3", 1);
           }   
      else return notify_fail("�㽫��������ת�˼��£����ʲôҲû������\n");
        }               
     return 1;
}

int do_ti(string arg)
{
         object me =this_player();          
         if (!me->query_temp("marks/��Ĺ3"))
           return 0;
         if (me->is_busy() || me->is_fighting())
           return notify_fail("����æ���ģ�\n");
         if ( arg =="up"){
           message_vision(YEL"$N������ס�˰�������һ��,ֻ������һ�죬�׵�ʯ��Ӧ�ֶ���
$N⧲���������������²�ʯ�ҡ�\n"NOR,me);
           me->delete_temp("marks/��Ĺ3");
           me->move(__DIR__"sshi1");
           return 1;
           }
        return notify_fail("���������᣿\n");
}


int do_canwu(string arg)
{
  object me=this_player();
  int ap;
  
 
  string *poem = ({
		"��ͽ֪����Ϣ˼Ϊ����֮�����ⲻ֪�ϴ�֮ʿ��Բͨ���ۣ�����˫�ޣ���������������������",
		"��֮���������Ŷ������㣬�ǹ���ʤʵ������ʤ���š����ⲩ������£���Ȥ����֮��֣�����֮���ң��仯֮�ɱ�����֮���¡�",
		"��֮ʤǿ����֮ʤ�գ�����Ī��֪��Ī���С�",
		"����֮���ᣬ�۳�����֮���ᡣ",
		"��ָ�������޼᲻�ƣ��ݵ����ԣ��紩������",
		"���������������Ծš�̫�������ǣ���س����С������Ѽ������߹�Ԫ̫�أ�̫��������£���֮�崿����֮ԨԴ��",
		});

    if(me->is_busy() )
          return notify_fail("������æ���أ����й���ǽ�ϵĶ���...\n");

    if((int)me->query_skill("literate",1) < 5000 )
               return notify_fail("�㿴��ǽ�ϵ����֣�һ��ãȻ��ʼ���޷�����\n");
   
     ap = me->query_skill("literate", 1) /1000;
   	
    if(me->query("jing") < 1000)
        {
        tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
        return 1;
        }	
    if(me->query("potential") < 1000)
        {
        tell_object(me,"���Ǳ�ܲ���.....��\n");     
        return 1;
        }	
        message_vision("$N��ϸ���о���ǽ�ϵ����֣�" + poem[random(sizeof(poem))] + "\n", me);
        me->add("jing",-100);
		me->add("potential",-100);
        me->start_busy(2);
    if(me->query("jiuyin/jm")) 
        {
        tell_object(me,"���Ѿ���ȫ�����˾����澭�ľ��裬����Ҫ���������ˡ�\n");       
        return 1;
        }
    if((int)me->query_skill("jiuyin-zhenjing", 1) > 1500)
		{
        tell_object(me,HIW"����ϸ�о�������ǽ���ϵ����֣���������ϰ����......\n"NOR);
        me->improve_skill("literate", 50+random(10));
		
        me->start_busy(2);
        }
    if( random(1000000) < me->query("kar") + ap )
        {
        me->add("jiuyin/jm",1);
		tell_object(me,HIG"���Ѿ���������澭�ľ���\n"NOR);
        }
        return 1;
}             