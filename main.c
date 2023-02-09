#include "monty.h"

/**
 * main - entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	        if (argc != 2)
			        {
					                fprintf(stderr, "USAGE: monty file\n");
							                exit(EXIT_FAILURE);
									        }

		        FILE *fp;
			        fp = fopen(argv[1], "r");

				        if (!fp)
						        {
								                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
										                exit(EXIT_FAILURE);
												        }

					        stack_t *stack = NULL;
						        instruction_t ops[] = {
								                {"push", push},
										                {"pall", pall},
												                {NULL, NULL}
										        };

							        unsigned int line_number = 0;
								        char *line = NULL;
									        size_t len = 0;

										        while (getline(&line, &len, fp) != -1)
												        {
														                line_number++;
																                char *opcode = strtok(line, " \n");

																		                if (opcode == NULL || *opcode == '#')
																					                        continue;

																				                int i;
																						                for (i = 0; ops[i].opcode != NULL; i++)
																									                {
																												                        if (strcmp(ops[i].opcode, opcode) == 0)
																																                                break;
																															                }

																								                if (ops[i].opcode == NULL)
																											                {
																														                        fprintf(stderr, "L%u: unknown instruction %s\n",
																																			                                line_number, opcode

