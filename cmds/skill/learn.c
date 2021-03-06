// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

nosave string *valid_learn_skill = ({
	"yijing-force", "taixuan-gong","xixing-dafa",
	});

nosave mapping valid_learn_type = get_mapping_config(DATA_CONFIG_DIR+"mapping/skill.mapp");

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	mapping skl;
	string skill, teacher, skill_name, *sname;
	int times, i, is_couple, flag;
	object ob,home;	
	int master_skill, my_skill, gin_cost;
	
	reset_eval_cost();

	if ( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

	if( !arg || arg=="?" || arg=="/?" )
		return notify_fail("指令格式：learn <技能> at <次数> from <某人>\n");

	if ( sscanf(arg, "%s at %d from %s", skill, times, teacher) != 3 )
	if ( sscanf(arg, "%s %s %d", teacher, skill, times) != 3 )
		return notify_fail("指令格式：learn <技能> at <次数> from <某人>\n");

	if ( times > 999 ) //原来99
		return notify_fail("一次学这么多,小心累到了哦~\n");

	if ( (int) times < 1 )
		me->set("learn_cuowu",1);

	if ( (int) times < 1 )
		return notify_fail("你要学几次？\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if (me->query("learned_points",1))
		return notify_fail("参数错误,有疑问请找巫师!\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( ob == me )
		return notify_fail("嗯....你得先生一个自己出来再说。\n");

	if( skill == "taixuan-gong" )
		return notify_fail("这项技能你只能领悟。\n");

	if( skill == "spells" )	
		return notify_fail("这项技能不能跟玩家学。\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
	
	is_couple = 0;
	if( !me->is_apprentice_of(ob) )
	{
		if ( me->query("couple/couple_id") == ob->query("id") 
			&& ob->query("couple/couple_id") == me->query("id") )
			is_couple = 1;
	}

	if ( !is_couple && !(ob->recognize_apprentice(me)) )
	{
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
		//return notify_fail(HIY"你虽然还是他的徒弟，他也还是你的师傅，可他早已另拜师门。\n你们既不在同一门派，辈份也不相符，又怎能私下交涉武技呢？\n");
	}

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if (ob->is_fighting())
		return notify_fail("师傅忙着料理别人，没空理你耶。\n");

	if( ob->query("startroom") )
	{
		if( !home = find_object(ob->query("startroom")) )
			home = load_object(ob->query("startroom"));

		if ( !userp(ob) && environment(ob) != home )
		{	
			message_vision(CYN"$N说道：我现在正忙着呢！等我回去再说吧！\n"NOR,ob);	
			return 1;
		}
	}

	my_skill = me->query_skill(skill, 1);
	
	// 有叛师记录的
	if ( ob->prevent_learn(me,my_skill) )
		return notify_fail(ob->name() + "不愿意教你这项技能。\n");
     //解决套装技能可以被其他玩家学习的bug
	if( my_skill >= (master_skill- ob->query_temp("suit_skill/"+skill)) )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	if( !SKILL_D(skill)->valid_learn(me) )
		return SKILL_D(skill)->valid_learn(me);
	// 特殊技能禁止和玩家学习
	if ( (string)SKILL_D(skill)->type() == "only_from_npc" && playerp(ob) )
		return notify_fail("这项技能不能和玩家学。\n");
	// lisa 2003.7.3
	if ( SKILL_D(skill)->valid_learn_ob(ob) )
	{
		if ( playerp(ob) ) return notify_fail("这项技能不能和玩家学。\n");
		if ( me->query("gender") == "无性" 
			&& my_skill > 49 
			&& skill!="kuihua-xinfa" 
			&& skill!="yijing-force" ) 
			return notify_fail("你无根无性，阴阳不调，难以领会高深的"+to_chinese(skill)+"。\n");
		
		if ( member_array(skill, valid_learn_skill) == -1 )
		{
			flag = valid_learn_type[skill];
			skl = me->query_skills();
			sname  = keys(skl);
			for ( i=0; i<sizeof(sname); i++ )
			{
				if ( !SKILL_D(sname[i])->valid_learn_ob(ob) ) continue; // 不是内功
				if ( sname[i] == skill ) continue; // 自己本身
				if ( member_array(sname[i], valid_learn_skill) != -1 ) continue; // 允许兼容的内功
				if ( flag && valid_learn_type[sname[i]] == flag ) continue; // 一些特殊例外
				return notify_fail("你不先散了别派内功，怎能学"+to_chinese(skill)+"？\n"NOR);
			}
		}
	}

	gin_cost = (100 + my_skill * 2) / (int) me->query_int();

	if ( gin_cost < 1 )
		gin_cost = 1;
	
	if( !my_skill )
	{
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	
	if( (int)times > (int)me->query("potential") )
	{
		if ( me->query("potential") < 1 )
			return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
		else
			return notify_fail("你的潜能不够学习这么多次了。\n");
	}
	
	if ( me->query("jing") < 1 )
		return notify_fail("你已经太累了，没有办法再继续学习。\n");

	printf("你向%s请教有关「%s」的疑问。\n", ob->name(), to_chinese(skill));
	
	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");
	
	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n", me->name(), to_chinese(skill)));
	
	if( (int)ob->query("jing") > gin_cost * times / 5 )
	{
		if( userp(ob) )
			ob->receive_damage("jing", gin_cost * times / 5 + 1);
		else
			ob->receive_damage("jing", gin_cost * times / 10 + 1);
	}
	else
	{
		write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}

	if( (int)me->query("jing") >= times * gin_cost )
	{
		if( (string)SKILL_D(skill)->type() == "martial" 
		&& (my_skill+1) * (my_skill+1) / 10 * to_float(my_skill+1) 
			>= me->get_levelup_exp()/2*(me->query("xyzx_sys/level")+1) )
		{  	
			printf("你的等级不足，对%s的回答总是无法领会。\n", ob->name() );
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(), skill_name);
			else
				printf("你听了%s的指导，似乎有些心得。\n", ob->name());

			for ( i = 0; i < times; i++ )
			{
				if(me->query_skill(skill,1)>= (master_skill - ob->query_temp("suit_skill/"+skill)))
                    break; //解决套装技能可以被其他玩家学习的bug
				if( !SKILL_D(skill)->valid_learn(me) )
					break; //解决在武功本身代码里有限制最高学习技能等级的时候，仍然可以溢出学习的bug
				me->improve_skill(skill, 5 * (10 + random((int)me->query_int() - 9)));
			}

			me->add("potential", -(int)times);
			me->receive_damage("jing", times * gin_cost);
		}
	}
	else
	{
		gin_cost = me->query("jing");
		me->receive_damage("jing", gin_cost);
		write("你今天太累了，结果什么也没有学到。\n");
	}

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : learn <技能> at <次数> from <某人>
 
这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。
此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。
其他相关指令 : teach, apprentice, practice, skills, study
HELP
        );
        return 1;
}
