import { Link } from 'react-router-dom';
import illustration from '../assets/illustration.svg';
import { motion } from 'framer-motion';

export default function Home() {
    return (
        <motion.div
            className="py-16 px-4 space-y-24 max-w-screen-lg mx-auto bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100"
            initial={{ opacity: 0, y: 10 }}
            animate={{ opacity: 1, y: 0 }}
            exit={{ opacity: 0, y: -10 }}
            transition={{ duration: 0.4 }}
        >
            <section className="space-y-6 text-center">
                <motion.h2
                    className="text-2xl sm:text-3xl md:text-5xl font-bold leading-tight"
                    initial={{ opacity: 0, y: 20 }}
                    animate={{ opacity: 1, y: 0 }}
                    transition={{ delay: 0.2 }}
                >
                    Zarządzaj częściami samochodowymi{' '}
                    <span className="text-blue-600">łatwiej niż kiedykolwiek!</span>
                </motion.h2>

                <motion.p
                    className="text-md sm:text-lg md:text-xl max-w-3xl mx-auto text-gray-500 dark:text-gray-300"
                    initial={{ opacity: 0 }}
                    animate={{ opacity: 1 }}
                    transition={{ delay: 0.4 }}
                >
                    Pełna kontrola magazynu części samochodowych w jednym, przejrzystym miejscu.
                </motion.p>

                <motion.div
                    className="flex flex-col sm:flex-row justify-center gap-4 items-center"
                    initial={{ opacity: 0 }}
                    animate={{ opacity: 1 }}
                    transition={{ delay: 0.6 }}
                >
                    <Link
                        to="/offer"
                        className="bg-blue-600 hover:bg-blue-700 text-white px-6 py-3 rounded-lg shadow-md transition-transform duration-300 hover:scale-105"
                    >
                        Zobacz ofertę
                    </Link>
                    <Link
                        to="/contact"
                        className="bg-green-600 hover:bg-green-700 text-white px-6 py-3 rounded-lg shadow-md transition-transform duration-300 hover:scale-105"
                    >
                        Skontaktuj się z nami
                    </Link>
                </motion.div>
            </section>

            <motion.section
                className="bg-gray-100 dark:bg-gray-800 py-12 rounded-lg shadow-inner px-4"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.8 }}
            >
                <div className="grid grid-cols-1 md:grid-cols-3 gap-8 justify-center">
                    {[
                        {
                            icon: '⚙️',
                            title: 'Zarządzanie magazynem',
                            desc: 'Pełna kontrola nad stanem części samochodowych.'
                        },
                        {
                            icon: '📦',
                            title: 'Śledzenie stanów',
                            desc: 'Bądź na bieżąco z poziomem zapasów i stanem minimalnym.'
                        },
                        {
                            icon: '🧾',
                            title: 'Szybkie dodawanie',
                            desc: 'Dodawaj nowe części w kilka sekund.'
                        }
                    ].map((item) => (
                        <motion.div
                            key={item.title}
                            className="bg-white dark:bg-gray-700 p-6 rounded-lg shadow hover:shadow-xl transition-all transform hover:scale-105 duration-300 text-center"
                            whileHover={{ scale: 1.05 }}
                        >
                            <div className="text-4xl mb-2">{item.icon}</div>
                            <h3 className="text-lg font-semibold mb-1">{item.title}</h3>
                            <p className="text-gray-600 dark:text-gray-300 text-sm">{item.desc}</p>
                        </motion.div>
                    ))}
                </div>
            </motion.section>

            <motion.section
                className="flex flex-col md:flex-row items-center gap-8 bg-gradient-to-r from-blue-50 to-blue-100 dark:from-gray-800 dark:to-gray-700 rounded-xl p-6 md:p-10 shadow-lg"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 1.0 }}
            >
                <motion.div
                    className="w-full md:w-1/2 flex justify-center bg-white dark:bg-gray-700 p-4 md:p-6 rounded-lg shadow"
                    whileHover={{ scale: 1.03 }}
                >
                    <img
                        src={illustration}
                        alt="Ilustracja"
                        className="max-w-full h-auto transform hover:scale-105 transition-transform duration-500"
                    />
                </motion.div>
                <div className="w-full md:w-1/2 text-left space-y-4">
                    <h3 className="text-2xl md:text-3xl font-bold">Nowoczesny interfejs</h3>
                    <p className="text-gray-600 dark:text-gray-300 text-sm sm:text-base">
                        Nasz system został zaprojektowany z myślą o prostocie i szybkości obsługi. Dzięki przejrzystemu interfejsowi znajdziesz potrzebne informacje błyskawicznie.
                    </p>
                </div>
            </motion.section>

            <motion.section
                className="bg-gradient-to-r from-blue-500 to-indigo-500 py-10 rounded-lg shadow-lg text-white text-center space-y-4"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 1.2 }}
            >
                <h4 className="text-xl sm:text-2xl font-semibold">Gotowy, aby zacząć?</h4>
                <Link
                    to="/pricing"
                    className="inline-block bg-white text-blue-600 px-6 py-3 rounded-lg shadow-md font-semibold hover:scale-105 transition-transform duration-300"
                >
                    Zobacz nasze plany
                </Link>
            </motion.section>
        </motion.div>
    );
}
