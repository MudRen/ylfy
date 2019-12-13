// blade-book.c

inherit ITEM;

void create()
{
	set_name( "���ҵ��ײ�ƪ",({ "blade book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long","����һ�����ҵ��׵ļ�ҳ��ƪ��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
"name":         "hujia-dao",      //name of the skill	
                        "exp_required": 1000 ,        //minimum combat experience required
			"jing_cost":    20+random(20),// jing cost every time study this
			"difficulty":	20,           // the base int to learn this skill
			"min_skill":	30,           // the minimum level you can learn
"max_skill":    101            // the maximum level you can learn	
		]) );
	}
}
int query_autoload() { return 1; }
void init()
{
if( this_player() == environment() )
{
add_action("do_study", "study");
add_action("do_study", "du");
}
}

int do_study(string arg)
{
int skill_level;
object me=this_player(); 	
skill_level=me->query_skill("hujia-dao",1);
if ( me->is_fighter())
{
tell_object(me,"ս�����޷��Ķ���֪��\n");
return 1;
}
if (me->is_busy()){
tell_object(me,"��������æ���ء�\n");
return 1;}

if(skill_level >= 101) {	
tell_object(me,"����ϸ���о����Ȿ�飬�������������������̫ǳ�ˡ�\n");
return 1;}

if (me->query_skill("blade",1) < 350){
tell_object(me,"��Ļ��������������������޷�������ҵ��ľ��衣\n");
return 1;}



/*if( (int)me->query("combat_exp") < (int)skill_level*skill_level*skill_level/10 ) {
write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
return 1;}*/

if (me->query("jing") < 20) {
tell_object(me,"��̫���ˣ�������Ϣһ�°ɣ�\n");
return 1;}
me->receive_damage("jing", 20);
me->improve_skill("hujia-dao", (me->query_skill("hujia-dao")+me->query_int()));
message_vision("$N����ר���ж����ҵ�����\n", me);
return 1;
}
