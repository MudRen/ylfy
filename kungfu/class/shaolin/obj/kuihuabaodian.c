// kuihua.c ��������ԭ�� �������յ�
// by.suimeng    2015.3.19
inherit ITEM;
void setup()
{}
void init()
{
     if (this_player()==environment()){
        add_action("do_lingwu", "lingwu");
    }
}
void create()
{
        set_name(YEL"��������", ({ "kuihua baodian"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ֵ�һ�ؼ����������䡷��ԭ�����Ȿ�ͽ�������������ʲô��ͬ�أ����Բ�͸(lingwu)�¡�\n");
                set("value", 50000);
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}

int do_lingwu(string arg)
{
	object me = this_player();       
	int ap;
	
  string *poem = ({
		"Ӧ����Բ������ȴ�������������Ů������������Ե������,���������������㣬���������в�¡�",
		"����Һ�������������£�ǰ�󹲷�����ʮ���Σ����а��գ�������Ӥͯ����",
		"�������裬���˲�ͣ������֮Һ����ʮ��֮�������̶����档�˾�����֮�þã���������Ϊ�档",
		"������Ǧ���ĵù���Ǧ�����������ڽ��ж��ɵ��������ޱ���Ǧ��������������Դ�������ս�ǧ�",
		"ɨ�����������ӹ��棬������Ȼ����������磬�������ܡ�",
		"�䷨��������֮���������������ѹ���֣�����Ħ������ǧ�����Ի���",
		"����֮����˼ɫ�ǿࡣ������룬�Դ��Ծ����Ծ��Ժ������黨������������Ѩ�����㵤�",
		});

    if(me->is_busy() )
          return notify_fail("������æ���أ����й���������������ϵĶ���...\n");
    
    if((int)me->query_skill("literate",1) < 5000 )
               return notify_fail("����ϸ�����˿������䣬����һ��ãȻ��\n");
    
	ap = me->query_skill("literate", 1) /1000;
	
	if (me->query_skill("kuihua-xinfa",1) < 3000)
        {
        tell_object(me,"�ƺ�......�����ķ�.............\n"); 
        return 1;
        }

    if(me->query("jing") < 1000)
        {
        tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
        return 1;
        }
        message_vision("$N��ϸ�������ſ�������İ��أ�" + poem[random(sizeof(poem))] + "\n", me);
        me->add("jing",-100);
        me->start_busy(2);
		
    if(me->query("kuihua/rao_perform")) 
        {
        tell_object(me,"���Ѿ���ȫ�����˿����ķ��ľ��裬����Ҫ�������ˡ�\n");       
        return 1;
        }
    if((int)me->query_skill("kuihua-xinfa", 1) > 3000)
		{
        tell_object(me,HIW"����ϸ�о��Ȿԭ��ġ��������䡷����������ϰ����......\n"NOR);                	
        me->start_busy(2);
        }
    if( random(500000) < me->query("kar") + ap)
        {
        me->add("kuihua/rao_perform",1);
        tell_object(me,HIG"��ͻȻ�������"HIY"ԭ���������侫�边Ȼ�ڴ�!!!"HIR"��\n"NOR);      				
        }
        return 1;
}             
int query_autoload() { return 1; }